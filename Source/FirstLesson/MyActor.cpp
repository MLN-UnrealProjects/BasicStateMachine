// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "MyObject.h"
#include "MySceneComponent.h"
#include "EngineUtils.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("MYActor constructor called on %p"), this);

	//CreateDefaultSub Può essere chiamato solo nei costruttori
	Root = CreateDefaultSubobject<UMySceneComponent>("Root");
	SetRootComponent(Root);

	NotRoot = CreateDefaultSubobject<USceneComponent>("NotRoot");
	NotRoot->SetupAttachment(RootComponent);
}

AMyActor::~AMyActor()
{
	UE_LOG(LogTemp, Error, TEXT("MYActor deconstructor called on %p"), this);
}
float AMyActor::GetValue() const
{
	return Value;
}
void AMyActor::SetValue(const float NewValue)
{
	Value = NewValue;
}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Obj = NewObject<UMyObject>();

	if (Obj)
	{
		UClass* Class = Obj->GetClass();
		TFieldIterator<UProperty> PropsIt(Class);
		for (; PropsIt; ++PropsIt)
		{
			UProperty* CurrentProp = *PropsIt;
			UE_LOG(LogTemp, Warning, TEXT("Property Name: %s"), *CurrentProp->GetName());
		}

		//UFunction ExecuteUbergraph è gia presente e si riferisce alla blueprint
		TFieldIterator<UFunction> FunctsIt(Class);
		for (; FunctsIt; ++FunctsIt)
		{
			UFunction* CurrentFunc = *FunctsIt;
			UE_LOG(LogTemp, Warning, TEXT("Function Name: %s"), *CurrentFunc->GetName());
		}
	}

	TActorIterator<AActor> ActorsIt(GetWorld());
	for (; ActorsIt; ++ActorsIt)
	{
		AActor* CurrentActor = *ActorsIt;
		UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s, Class: %s"), *CurrentActor->GetName(), *CurrentActor->GetClass()->GetName());
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

