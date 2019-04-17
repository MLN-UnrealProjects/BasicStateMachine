// Fill out your copyright notice in the Description page of Project Settings.


#include "TestState.h"
#include "StateMachine.h"
#include "GameFramework/Actor.h"

void UTestState::OnStateEnter(const UStateMachine* const StateMachine)
{
	UE_LOG(LogTemp, Warning, TEXT("OnStateEnter from %s! Our State Index is: %d in SM %s owned by: %s"),*this->GetName(), StateMachine->GetCurrentStateIndex(), *StateMachine->GetName(), *StateMachine->GetOwner()->GetName());
}
void UTestState::OnStateUpdate(UStateMachine* const StateMachine)
{
	UE_LOG(LogTemp, Warning, TEXT("OnStateUpdate from %s! Our State Index is: %d in SM %s owned by: %s"), *this->GetName(), StateMachine->GetCurrentStateIndex(), *StateMachine->GetName(), *StateMachine->GetOwner()->GetName());
	const int32 NextStateIndex = StateMachine->GetCurrentStateIndex() + 1;
	StateMachine->ChangeState(NextStateIndex >= StateMachine->GetStatesCount() ? 0 : NextStateIndex);
}
void UTestState::OnStateExit(const UStateMachine* const StateMachine)
{
	UE_LOG(LogTemp, Warning, TEXT("OnStateExit from %s! Our State Index is: %d in SM %s owned by: %s"), *this->GetName(), StateMachine->GetCurrentStateIndex(), *StateMachine->GetName(), *StateMachine->GetOwner()->GetName());
}