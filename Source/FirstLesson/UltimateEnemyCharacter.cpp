// Fill out your copyright notice in the Description page of Project Settings.


#include "UltimateEnemyCharacter.h"
#include "UltimateAIController.h"
// Sets default values
AUltimateEnemyCharacter::AUltimateEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AUltimateAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AutoPossessPlayer = EAutoReceiveInput::Type::Disabled;

}

// Called when the game starts or when spawned
void AUltimateEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUltimateEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUltimateEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

