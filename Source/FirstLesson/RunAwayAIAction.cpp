// Fill out your copyright notice in the Description page of Project Settings.


#include "RunAwayAIAction.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
URunAwayAIAction::URunAwayAIAction()
{
	Target = nullptr;
	MaxScoreValue = 1500.0f;
	IdentityDistance = 800.f;
	ScaleValue = 1.f;
}
void URunAwayAIAction::Run(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	if (Pawn && Target)
	{
		Pawn->AddMovementInput((Pawn->GetActorLocation() - Target->GetActorLocation()).GetSafeNormal(), ScaleValue, true);
	}
}

AActor* URunAwayAIAction::FindTarget_Implementation()
{
	APlayerController* const PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		APawn* const PlayerPawn = PlayerController->GetPawn();
		if (PlayerPawn)
		{
			return PlayerPawn;
		}
	}
	return PlayerController;
}
float URunAwayAIAction::GetScore(AActor* InTarget, APawn* Pawn)
{
	const float Distance = FVector::Distance(Pawn->GetActorLocation(), InTarget->GetActorLocation());
	if (Distance == 0.f)
	{
		return MaxScoreValue;
	}
	return FMath::Min(MaxScoreValue, IdentityDistance / Distance);
}
float URunAwayAIAction::ReceiveScore_Implementation(AAIController* Controller, APawn* Pawn)
{
	Super::ReceiveScore_Implementation(Controller, Pawn);
	if (!Pawn)
	{
		return 0.f;
	}
	if (!Target)
	{
		Target = FindTarget();
	}
	if (Target && Pawn)
	{
		return GetScore(Target, Pawn);
	}
	return 0.f;
}
AActor* URunAwayAIAction::GetCurrentTarget() const
{
	return Target;
}
void URunAwayAIAction::Tick(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	Super::Tick(DeltaTime, Controller, Pawn);
	Run(DeltaTime, Controller, Pawn);
}