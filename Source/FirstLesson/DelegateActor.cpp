// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateActor.h"

// Sets default values
ADelegateActor::ADelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADelegateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnStuff.Broadcast(DeltaTime, GetName());
}

