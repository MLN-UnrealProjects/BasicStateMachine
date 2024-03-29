// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateMachine.generated.h"

#define INVALID_STATEMACHINE_INDEX -1

class UState;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
/*
* Simple component for a particular type of State Machine using UState assets
*/
class FIRSTLESSON_API UStateMachine : public UActorComponent
{
	GENERATED_BODY()
private:
	int32 CurrentStateIndex;
	UState* CurrentState;
	UPROPERTY()
	TArray<UState*> States;
public:	
	// Sets default values for this component's properties
	UStateMachine();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = "Config|StateMachine")
	bool bAutoInitialize = true;
	UPROPERTY(EditAnywhere, Category = "Config|StateMachine")
	int32 StartingStateIndex = 0;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	void ClearInvalidStates();
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	void ClearStates();
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	int32 AddState(UState* const ToAdd);
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	int32 AddStates(const TArray<UState*>& ToAdd);
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	int32 RemoveStates(const TArray<UState*>& ToRemove);
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	int32 RemoveStatesIndex(const TArray<int32>& ToRemove);
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	bool RemoveState(UState* const ToRemove);
	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	bool RemoveStateIndex(const int32 StateIndexToRemove);

	UFUNCTION(BlueprintCallable, Category = "Config|StateMachine")
	void ChangeState(const int32 NewStateIndex);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	bool IsCurrentStateIndexValid() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	bool IsGivenIndexValid(const int32 Index) const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	int32 GetCurrentStateIndex() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	int32 GetStatesCount() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	int32 GetStateIndex(UState* const State) const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	int32 GetInvalidStateIndexValue() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	UState* GetCurrentState() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config|StateMachine")
	UState* GetState(const int32 Index) const;
};
