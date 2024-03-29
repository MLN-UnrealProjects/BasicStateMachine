// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
class UStateMachine;
UCLASS()
class FIRSTLESSON_API AMyAIController : public AAIController
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly)
	UStateMachine* StateMachine;
public:
	AMyAIController();
};
