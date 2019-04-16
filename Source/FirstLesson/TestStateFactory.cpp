// Fill out your copyright notice in the Description page of Project Settings.


#include "TestStateFactory.h"
#include "TestState.h"
#include "AssetTypeCategories.h"

UTestStateFactory::UTestStateFactory()
{
	bCreateNew = true;
	SupportedClass = UTestState::StaticClass();
}

UObject* UTestStateFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTestState>(InParent, InClass, InName, Flags);
}
FText UTestStateFactory::GetDisplayName() const
{
	return FText::FromString(TEXT("Useless State"));
}
uint32 UTestStateFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Blueprint;
}