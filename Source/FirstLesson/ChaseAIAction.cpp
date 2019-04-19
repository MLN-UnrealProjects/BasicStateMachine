// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseAIAction.h"
UChaseAIAction::UChaseAIAction()
{
	IdentityDistance = 700.f;
	MaxScoreValue = 1500.f;
}
void UChaseAIAction::Run(float DeltaTime, AAIController* Controller, APawn* Pawn)
{
	const AActor* const CurrTarget = GetCurrentTarget();
	if (Pawn && CurrTarget)
	{
		Pawn->AddMovementInput((CurrTarget->GetActorLocation() - Pawn->GetActorLocation()).GetSafeNormal(), ScaleValue, true);
	}
}
float UChaseAIAction::GetScore(AActor* InTarget, APawn* Pawn)
{
	const float Distance = FVector::Distance(Pawn->GetActorLocation(), InTarget->GetActorLocation());
	if (IdentityDistance == 0.f)
	{
		return MaxScoreValue;
	}
	return FMath::Min(MaxScoreValue, Distance / IdentityDistance);
}