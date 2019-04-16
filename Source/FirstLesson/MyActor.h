// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

class UMyObject;
class UMySceneComponent;
//Gli actor vivono in un UWorld (ce ne possono essere tanti contemporaneamente di uworlds, per esempio viewport, static mesh visualizzazione etc)
UCLASS()
class FIRSTLESSON_API AMyActor : public AActor
{
	GENERATED_BODY()
private:
	float Value;

protected:
	UPROPERTY()
	UMySceneComponent* Root;
	UPROPERTY()
	USceneComponent* NotRoot;
	//UProperty permette al garbage collector di "vedere" questo campo e capire di conseguenza se un oggetto è referenziato da questo campo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|Test")
	UMyObject* Obj;
public:
	// Sets default values for this actor's properties
	AMyActor();
	~AMyActor();

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Config|Test")
	float GetValue() const;
	UFUNCTION(BlueprintCallable, Category = "Config|Test")
	void SetValue(const float NewValue);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
