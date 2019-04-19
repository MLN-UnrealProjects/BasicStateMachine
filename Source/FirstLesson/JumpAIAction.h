// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAIAction.h"
#include "JumpAIAction.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FIRSTLESSON_API UJumpAIAction : public UUtilityAIAction
{
	GENERATED_BODY()
private:
	float LastActivationTime;
public:
	UJumpAIAction();
	void Enter(AAIController* Controller, APawn* Pawn) override;
	float ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn) override;

	UPROPERTY(EditAnywhere, Category = "Config")
	float JumpForce;
	UPROPERTY(EditAnywhere, Category = "Config")
	float Interval;
	UPROPERTY(EditAnywhere, Category = "Config")
	float MaxScore;
};
