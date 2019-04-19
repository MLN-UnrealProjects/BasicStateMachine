// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpAIAction.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
UJumpAIAction::UJumpAIAction()
{
	JumpForce = 300.f;
	Interval = 5.f;
	MaxScore = 80000.f;
	LastActivationTime = 0.f;
}
void UJumpAIAction::Enter(AAIController* Controller, APawn* Pawn)
{
	if (Pawn)
	{
		ACharacter* const Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			Character->LaunchCharacter(Pawn->GetActorUpVector() * JumpForce, false, true);
		}
	}
	LastActivationTime = GetWorld()->TimeSeconds;
}
float UJumpAIAction::ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn)
{
	if (Pawn)
	{
		ACharacter* const Character = Cast<ACharacter>(Pawn);
		if (Character && GetWorld()->TimeSeconds - LastActivationTime >= Interval)
		{
			return MaxScore;
		}
	}
	return 0.f;
}