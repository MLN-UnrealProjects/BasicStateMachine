// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "StateMachine.h"
#include "TestState.h"
AMyAIController::AMyAIController()
{
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