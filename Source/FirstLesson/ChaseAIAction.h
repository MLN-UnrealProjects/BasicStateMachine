// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RunAwayAiAction.h"
#include "ChaseAIAction.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FIRSTLESSON_API UChaseAIAction : public URunAwayAIAction
{
	GENERATED_BODY()
public:
	UChaseAIAction();
protected:
	void Run(float DeltaTime, AAIController* Controller, APawn* Pawn) override;
	float GetScore(AActor* InTarget, APawn* Pawn) override;
};
