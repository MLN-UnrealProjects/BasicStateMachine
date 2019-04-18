// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"
//Oggessti figli di uobject devono usare dynamic delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMyDelegate, float, A, FString, Text);

UCLASS()
class FIRSTLESSON_API ADelegateActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADelegateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable)
	FMyDelegate OnStuff;

};
