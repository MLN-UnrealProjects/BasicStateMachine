// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 *
 */
 //unreal engine header tool (programma c#) controlla tutti i file h e, trovate define del tipo di UClass etc.. crea un nuovo header (.generated.h). Verra compilato quell'header al posto di quello di base
UCLASS(BlueprintType)
//FIRSTLESSON_API permette di esportare simbolo in dll
class FIRSTLESSON_API UMyObject : public UObject
{
	//implementazione refrection usando too di unreal
	GENERATED_BODY()
		UMyObject();
	~UMyObject();

public:
	UPROPERTY(EditAnywhere)
		float Value;

	UPROPERTY(EditAnywhere)
		FText Text;

	UFUNCTION()
	void Nothing1() const {}
	UFUNCTION()
	void Nothing2() const {}
	void Nothing3() const {}
};
