// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAIAction.h"
#include "WhatAmIDoingWithMyLifeAIAction.generated.h"
#define MY_INVALID_NAME TEXT("NONE")
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FIRSTLESSON_API UWhatAmIDoingWithMyLifeAIAction : public UUtilityAIAction
{
	GENERATED_BODY()
public:
	UWhatAmIDoingWithMyLifeAIAction();
	void Enter(AAIController* Controller, APawn* Pawn) override;
	float ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn) override;
	bool ReceiveCanRun_Implementation(AAIController* Controller, APawn* Pawn) const override;
	void Tick(float DeltaTime, AAIController* Controller, APawn* Pawn) override;
	void Exit(AAIController* Controller, APawn* Pawn) override;
	void Spawn(AAIController* Controller) override;

	UPROPERTY(EditAnywhere, Category = "Config")
	float MaxScore;
};
