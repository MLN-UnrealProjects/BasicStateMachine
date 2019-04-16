// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "StateMachine.h"
#include "TestState.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Movement = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("Movement"));
	if (Movement)
	{
		Movement->UpdatedComponent = RootComponent;
	}
	StateMachine = CreateDefaultSubobject<UStateMachine>(TEXT("State Machine"));
	AddInstanceComponent(StateMachine);
	StateMachine->RegisterComponent();
	if (StateMachine)
	{
		for (size_t i = 0; i < 5; i++)
		{
			StateMachine->AddState(NewObject<UTestState>());
		}
		if (!StateMachine->IsCurrentStateIndexValid())
		{
			StateMachine->ChangeState(0);
		}
	}
}
UPawnMovementComponent* AMyPawn::GetMovementComponent() const
{
	return Movement;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindKey(EKeys::SpaceBar, EInputEvent::IE_Pressed, this, &AMyPawn::Up);
	}
}

void AMyPawn::Up()
{
	AddMovementInput(FVector::UpVector);
}