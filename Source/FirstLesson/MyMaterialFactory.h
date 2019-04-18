// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MyMaterialFactory.generated.h"

/**
 *
 */
UCLASS()
class FIRSTLESSON_API UMyMaterialFactory : public UFactory
{
	GENERATED_BODY()
public:
	UMyMaterialFactory();
	UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	//uint32 GetMenuCategories() const override;
	FText GetDisplayName() const override;
};
