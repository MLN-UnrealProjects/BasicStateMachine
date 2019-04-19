// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UltimateAIController.generated.h"

/**
 * 
 */
class UUtilityAIComponent;
UCLASS()
class FIRSTLESSON_API AUltimateAIController : public AAIController
{
	GENERATED_BODY()
	UPROPERTY()
	UUtilityAIComponent* UtilityAI;
public:
	AUltimateAIController();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Config")
	UUtilityAIComponent* GetUtilityAIComponent() const;
};
