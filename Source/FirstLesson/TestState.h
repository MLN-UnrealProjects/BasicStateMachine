// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "TestState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTLESSON_API UTestState : public UState
{
	GENERATED_BODY()
protected:

	void OnStateEnter(const UStateMachine* const StateMachine) override;
	void OnStateUpdate(UStateMachine* const StateMachine) override;
	void OnStateExit(const UStateMachine* const StateMachine) override;
};
