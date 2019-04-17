// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "State.h"

// Sets default values for this component's properties
UStateMachine::UStateMachine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentStateIndex = INVALID_STATEMACHINE_INDEX;
	CurrentState = nullptr;

	// ...
}
int32 UStateMachine::GetStatesCount() const
{
	return States.Num();
}
void UStateMachine::ChangeState(const int32 NewStateIndex)
{
	if (CurrentState)
	{
		CurrentState->OnStateExit(this);
	}
	CurrentState = nullptr;
	CurrentStateIndex = NewStateIndex;
	if (IsCurrentStateIndexValid())
	{
		CurrentState = States[CurrentStateIndex];
		if (CurrentState)
		{
			CurrentState->OnStateEnter(this);
		}
	}
}
void UStateMachine::ClearInvalidStates()
{
	for (size_t i = States.Num() - 1; i >= 0; i--)
	{
		if (States[i] == nullptr)
		{
			RemoveStateIndex(i);
		}
	}
}

UState* UStateMachine::GetCurrentState() const
{
	return CurrentState;
}
bool UStateMachine::IsCurrentStateIndexValid() const
{
	return IsGivenIndexValid(CurrentStateIndex);
}
bool UStateMachine::IsGivenIndexValid(const int32 Index) const
{
	return Index != INVALID_STATEMACHINE_INDEX && Index >= 0 && Index < States.Num();
}
int32 UStateMachine::GetCurrentStateIndex() const
{
	return CurrentStateIndex;
}
int32 UStateMachine::GetInvalidStateIndexValue() const
{
	return INVALID_STATEMACHINE_INDEX;
}
void UStateMachine::ClearStates()
{
	ChangeState(INVALID_STATEMACHINE_INDEX);
	States.Empty();
}
int32 UStateMachine::AddStates(const TArray<UState*>& ToAdd)
{
	int32 Count = 0;
	for (auto const Item : ToAdd)
	{
		const int32 AddedIndex = AddState(Item);
		Count += (IsGivenIndexValid(AddedIndex));
	}
	return Count;
}
int32 UStateMachine::GetStateIndex(UState* const State) const
{
	if (State == nullptr)
	{
		return INVALID_STATEMACHINE_INDEX;
	}
	return States.Find(State);
}
int32 UStateMachine::RemoveStatesIndex(const TArray<int32>& ToRemove)
{
	int32 Count = 0;
	for (auto const Item : ToRemove)
	{
		Count += (RemoveStateIndex(Item));
	}
	return Count;
}
int32 UStateMachine::RemoveStates(const TArray<UState*>& ToRemove)
{
	int32 Count = 0;
	for (auto const Item : ToRemove)
	{
		Count += (RemoveState(Item));
	}
	return Count;
}
int32 UStateMachine::AddState(UState* const ToAdd)
{
	if (ToAdd == nullptr)
	{
		return INVALID_STATEMACHINE_INDEX;
	}
	return States.AddUnique(ToAdd);
}
bool UStateMachine::RemoveState(UState* const ToRemove)
{
	if (ToRemove == nullptr)
	{
		return false;
	}
	if (CurrentState == ToRemove)
	{
		RemoveStateIndex(CurrentStateIndex);
		return true;
	}

	return RemoveStateIndex(States.Find(ToRemove));
}
bool UStateMachine::RemoveStateIndex(const int32 StateIndexToRemove)
{
	if (!IsGivenIndexValid(StateIndexToRemove))
	{
		return false;
	}
	if (CurrentStateIndex == StateIndexToRemove)
	{
		ChangeState(INVALID_STATEMACHINE_INDEX);
		States.RemoveAt(CurrentStateIndex);
		return true;
	}

	States.RemoveAt(StateIndexToRemove);

	CurrentStateIndex = States.Find(CurrentState);

	return true;
}
UState* UStateMachine::GetState(const int32 Index) const
{
	if (!IsGivenIndexValid(Index))
	{
		return nullptr;
	}
	return States[Index];
}

// Called when the game starts
void UStateMachine::BeginPlay()
{
	Super::BeginPlay();
	if (bAutoInitialize && !CurrentState && States.Num() > 0)
	{
		ChangeState(StartingStateIndex);
	}

	// ...

}


// Called every frame
void UStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentState)
	{
		CurrentState->OnStateUpdate(this);
	}
	else
	{
		ChangeState(INVALID_STATEMACHINE_INDEX);
	}
	// ...
}

