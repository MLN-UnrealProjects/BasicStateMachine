// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAIAction.h"
#include "RunAwayAIAction.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class FIRSTLESSON_API URunAwayAIAction : public UUtilityAIAction
{
	GENERATED_BODY()
private:
	AActor* Target;

protected:
	virtual void Run(float DeltaTime, AAIController* Controller, APawn* Pawn);
	virtual float GetScore(AActor* InTarget, APawn* Pawn);
public:
	URunAwayAIAction();

	float ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn) override;
	void Tick(float DeltaTime, AAIController* Controller, APawn* Pawn) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Config", meta = (DisplayName = "FindTarget"))
	AActor* FindTarget();
	AActor* FindTarget_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	AActor* GetCurrentTarget() const;

	UPROPERTY(EditAnywhere, Category = "Config")
	float MaxScoreValue;
	UPROPERTY(EditAnywhere, Category = "Config")
	float IdentityDistance;
	UPROPERTY(EditAnywhere, Category = "Config")
	float ScaleValue;
};
