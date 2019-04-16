// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

/**
 * Base state type
 */
class UStateMachine;
UCLASS(BlueprintType, Blueprintable, Abstract)
class FIRSTLESSON_API UState : public UObject
{
	GENERATED_BODY()

protected:

	UFUNCTION(Category="StateMachine")
	virtual void OnStateEnter(const UStateMachine* const StateMachine);
	UFUNCTION(Category = "StateMachine")
	virtual void OnStateUpdate(UStateMachine* const StateMachine);
	UFUNCTION(Category = "StateMachine")
	virtual void OnStateExit(const UStateMachine* const StateMachine);

	friend UStateMachine;
};
