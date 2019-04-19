// Fill out your copyright notice in the Description page of Project Settings.


#include "UltimateAIController.h"
#include "UtilityAIComponent.h"
#include "ChaseAIAction.h"
#include "RunAwayAIAction.h"
#include "JumpAIAction.h"
#include "WhatAmIDoingWithMyLifeAIAction.h"

AUltimateAIController::AUltimateAIController()
{
	UtilityAI = CreateDefaultSubobject<UUtilityAIComponent>(TEXT("UtilityAI"));

	UtilityAI->Actions.Add(UChaseAIAction::StaticClass());
	UtilityAI->Actions.Add(URunAwayAIAction::StaticClass());
	UtilityAI->Actions.Add(UJumpAIAction::StaticClass());
	UtilityAI->Actions.Add(UWhatAmIDoingWithMyLifeAIAction::StaticClass());
	UtilityAI->bIgnoreZeroScore = true;
	UtilityAI->Bounciness = 0.5f;
	UtilityAI->EqualityTolerance = 0.001f;

	AddInstanceComponent(UtilityAI);
	UtilityAI->RegisterComponent();

}
UUtilityAIComponent* AUltimateAIController::GetUtilityAIComponent() const
{
	return UtilityAI;
}