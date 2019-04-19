// Copyright 2018 Roberto De Ioris

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "UtilityAIAction.generated.h"

/**
 *
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class UNREALUTILITYAI_API UUtilityAIAction : public UObject
{
	GENERATED_BODY()

public:

	virtual UWorld* GetWorld() const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Config", meta = (DisplayName = "Spawn"))
	void ReceiveSpawn(AAIController* Controller);

	virtual void Spawn(AAIController* Controller);

	UFUNCTION(BlueprintImplementableEvent, Category = "Config", meta = (DisplayName = "Tick"))
	void ReceiveTick(float DeltaTime, AAIController* Controller, APawn* Pawn);

	virtual void Tick(float DeltaTime, AAIController* Controller, APawn* Pawn);

	UFUNCTION(BlueprintNativeEvent, Category = "Config", meta = (DisplayName = "Can Run"))
	bool ReceiveCanRun(AAIController* Controller, APawn* Pawn) const;

	virtual bool ReceiveCanRun_Implementation(AAIController* Controller, APawn* Pawn) const { return true; }

	virtual bool CanRun(AAIController* Controller, APawn* Pawn) const;

	UFUNCTION(BlueprintNativeEvent, Category = "Config", meta = (DisplayName = "Score"))
	float ReceiveScore(AAIController* Controller, APawn* Pawn);

	virtual float ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn) { return 0.f; };

	virtual float Score(AAIController* Controller, APawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "Config", meta = (DisplayName = "Enter"))
	void ReceiveEnter(AAIController* Controller, APawn* Pawn);

	virtual void Enter(AAIController* Controller, APawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "Config", meta = (DisplayName = "Exit"))
	void ReceiveExit(AAIController* Controller, APawn* Pawn);

	virtual void Exit(AAIController* Controller, APawn* Pawn);

	UPROPERTY(BlueprintReadOnly, Category = "Config")
	float LastScore;

	UPROPERTY(BlueprintReadOnly, Category = "Config")
	bool LastCanRun;

};
