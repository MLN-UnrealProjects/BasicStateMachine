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

	// ...
}
int32 UStateMachine::GetStatesCount() const
{
	return States.Num();
}
void UStateMachine::ChangeState(const int32 NewStateIndex)
{
	if (IsCurrentStateIndexValid())
	{
		UState* const State = States[CurrentStateIndex];
		if (State)
		{
			States[CurrentStateIndex]->OnStateExit(this);
		}
	}
	CurrentStateIndex = NewStateIndex;
	if (IsCurrentStateIndexValid())
	{
		UState* const State = States[CurrentStateIndex];
		if (State)
		{
			States[CurrentStateIndex]->OnStateEnter(this);
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
	if (!IsCurrentStateIndexValid())
	{
		return nullptr;
	}
	return States[CurrentStateIndex];
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
	if (IsCurrentStateIndexValid())
	{
		int32 FoundIndex = INVALID_STATEMACHINE_INDEX;
		const bool bFound{ States.Find(ToRemove, FoundIndex) };
		if (bFound)
		{
			RemoveStateIndex(FoundIndex);
		}
		return bFound;
	}

	return States.Remove(ToRemove) > 0;
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
	}
	States.RemoveAt(StateIndexToRemove);
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
	if (!IsCurrentStateIndexValid() && States.Num() > 0)
	{
		ChangeState(0);
	}

	// ...

}


// Called every frame
void UStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsCurrentStateIndexValid())
	{
		UState* const State = States[CurrentStateIndex];
		if (State)
		{
			State->OnStateUpdate(this);
		}
		else
		{
			ChangeState(INVALID_STATEMACHINE_INDEX);
		}
	}
	// ...
}

