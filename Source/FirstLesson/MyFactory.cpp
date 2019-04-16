// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFactory.h"
#include "MyObject.h"
#include "AssetTypeCategories.h"
UMyFactory::UMyFactory()
{
	bCreateNew = true;
	SupportedClass = UMyObject::StaticClass();
}

UObject* UMyFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UMyObject* Obj = NewObject<UMyObject>(InParent, InClass, InName, Flags);
	Obj->Value = 1.f;
	Obj->Text = GetDisplayName();
	return Obj;
}
FText UMyFactory::GetDisplayName() const
{
	return FText::FromString(TEXT("CIAO"));
}
uint32 UMyFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Blueprint;
}