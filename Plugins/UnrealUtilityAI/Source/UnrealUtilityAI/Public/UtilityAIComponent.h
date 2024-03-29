// Copyright 2018 Roberto De Ioris

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Core/Public/Math/RandomStream.h"
#include "UtilityAIAction.h"
#include "UtilityAIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUtilityAIActionSpawned, UUtilityAIAction*, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUtilityAIActionChanged, UUtilityAIAction*, NewAction, UUtilityAIAction*, OldAction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUtilityAIActionNotAvailable);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUtilityAIInitialized);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUtilityAIBeforeScoreComputation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUtilityAIActionChoosen, UUtilityAIAction*, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUtilityAIActionTicked, UUtilityAIAction*, Action);


UCLASS(BlueprintType, Blueprintable, ClassGroup = (AI), meta = (BlueprintSpawnableComponent))
class UNREALUTILITYAI_API UUtilityAIComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUtilityAIComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config", meta=(ExposeOnSpawn="true"))
	TSet<TSubclassOf<UUtilityAIAction>> Actions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bIgnoreZeroScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bUseLowestScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bInvertPriority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bRandomizeOnEquality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	float EqualityTolerance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	float Bounciness;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Action Spawned"))
	FUtilityAIActionSpawned OnUtilityAIActionSpawned;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Action Changed"))
	FUtilityAIActionChanged OnUtilityAIActionChanged;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Action Not Available"))
	FUtilityAIActionNotAvailable OnUtilityAIActionNotAvailable;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Initialized"))
	FUtilityAIInitialized OnUtilityAIInitialized;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Action Choosen"))
	FUtilityAIActionChoosen OnUtilityAIActionChoosen;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Action Ticked"))
	FUtilityAIActionChoosen OnUtilityAIActionTicked;

	UPROPERTY(BlueprintAssignable, Category = "Config", meta = (DisplayName = "On UtilityAI Before Score Computation"))
	FUtilityAIBeforeScoreComputation OnUtilityAIBeforeScoreComputation;

	UFUNCTION(BlueprintNativeEvent, Category = "Config", meta = (DisplayName = "Compute Best Action"))
	UUtilityAIAction* ReceiveComputeBestAction(AAIController* Controller, APawn* Pawn);

	UUtilityAIAction* ReceiveComputeBestAction_Implementation(AAIController* Controller, APawn* Pawn);

	virtual UUtilityAIAction* ComputeBestAction(AAIController* Controller, APawn* Pawn);


	UPROPERTY()
	TSet<UUtilityAIAction*> InstancedActions;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	TArray<UUtilityAIAction*> GetActionInstances() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	UUtilityAIAction* GetActionInstanceByClass(TSubclassOf<UUtilityAIAction> ActionClass) const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	UUtilityAIAction* GetCurrentActionInstance() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	TSubclassOf<UUtilityAIAction> GetCurrentActionClass() const;

	UFUNCTION(BlueprintCallable, Category = "Config")
	UUtilityAIAction* SpawnActionInstance(TSubclassOf<UUtilityAIAction> ActionClass);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	bool CanSpawnActionInstance(TSubclassOf<UUtilityAIAction> ActionClass) const;

	UFUNCTION(BlueprintCallable, Category = "Config")
	void SetRandomStream(FRandomStream InRandomStream);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	FRandomStream GetRandomStream() const;

	UFUNCTION(BlueprintNativeEvent, Category = "Config", meta = (DisplayName = "Score Filter"))
	float ScoreFilter(UUtilityAIAction* Action, float Score) const;

	float ScoreFilter_Implementation(UUtilityAIAction* Action, float Score) const { return Score; }

protected:

	UUtilityAIAction* LastAction;
	APawn* LastPawn;
	float LastSwitchTime;

	bool bUseRandomStream;
	FRandomStream RandomStream;

	bool InternalRandBool() const;

	bool CheckLowestScore(UUtilityAIAction* Current, UUtilityAIAction* Best) const;
	bool CheckHighestScore(UUtilityAIAction* Current, UUtilityAIAction* Best) const;
};
