// Fill out your copyright notice in the Description page of Project Settings.


#include "WhatAmIDoingWithMyLifeAIAction.h"

UWhatAmIDoingWithMyLifeAIAction::UWhatAmIDoingWithMyLifeAIAction()
{
	MaxScore = 1.5f;
}
void UWhatAmIDoingWithMyLifeAIAction::Enter(AAIController* Controller, APawn* Pawn)
{
	UE_LOG(LogTemp, Error, TEXT("%s Enter! Owned by %s"), *GetName(), Controller ? *Controller->GetName() : MY_INVALID_NAME);
}
float UWhatAmIDoingWithMyLifeAIAction::ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn)
{
	const float Random = FMath::RandRange(0.f, MaxScore);
	UE_LOG(LogTemp, Error, TEXT("%s ReceiveScore_Implementation with Score %f! Owned by %s"), *GetName(), Random, Controller ? *Controller->GetName() : MY_INVALID_NAME);
	return Random;
}
bool UWhatAmIDoingWithMyLifeAIAction::ReceiveCanRun_Implementation(AAIController* Controller, APawn* Pawn) const
{
	UE_LOG(LogTemp, Error, TEXT("%s ReceiveCanRun_Implementation! Owned by %s"), *GetName(), Controller ? *Controller->GetName() : MY_INVALID_NAME);
	return true;
}
void UWhatAmIDoingWithMyLifeAIAction::Tick(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	UE_LOG(LogTemp, Error, TEXT("%s Tick! Owned by %s"), *GetName(), Controller ? *Controller->GetName() : MY_INVALID_NAME);
}
void UWhatAmIDoingWithMyLifeAIAction::Exit(AAIController* Controller, APawn* Pawn)
{
	UE_LOG(LogTemp, Error, TEXT("%s Exit! Owned by %s"), *GetName(), Controller ? *Controller->GetName() : MY_INVALID_NAME);
}
void UWhatAmIDoingWithMyLifeAIAction::Spawn(AAIController* Controller)
{
	UE_LOG(LogTemp, Error, TEXT("%s Spawn! Owned by %s"), *GetName(), Controller ? *Controller->GetName() : MY_INVALID_NAME);
}