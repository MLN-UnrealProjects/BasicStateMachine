// Fill out your copyright notice in the Description page of Project Settings.


#include "TestState.h"
#include "StateMachine.h"
#include "GameFramework/Actor.h"

void UTestState::OnStateEnter(const UStateMachine* const StateMachine)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello from Test State! Our State Index is: %d in SM owned by: %s"), StateMachine->GetCurrentStateIndex(), *StateMachine->GetOwner()->GetName());
}
void UTestState::OnStateUpdate(UStateMachine* const StateMachine)
{
	const int32 NextStateIndex = StateMachine->GetCurrentStateIndex() + 1;
	StateMachine->ChangeState(NextStateIndex >= StateMachine->GetStatesCount() ? 0 : NextStateIndex);
}
void UTestState::OnStateExit(const UStateMachine* const StateMachine)
{

}