// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMaterialFactory.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionCosine.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionConstant4Vector.h"
#include "AssetTypeCategories.h"

UMyMaterialFactory::UMyMaterialFactory()
{
	bCreateNew = true;
	SupportedClass = UMaterial::StaticClass();
}
UObject* UMyMaterialFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UMaterial* const Mat = NewObject<UMaterial>(InParent, InClass, InName, Flags);

	auto* const Expression = NewObject<UMaterialExpressionConstant4Vector>(Mat);
	Expression->Constant = FLinearColor(1.f, 0.f, 0.f, 1.f);
	Mat->Expressions.Add(Expression);
	Mat->EmissiveColor.Connect(0, Expression);

	Mat->PostEditChange();
	
	return Mat;
}
FText UMyMaterialFactory::GetDisplayName() const
{
	return FText::FromString(TEXT("MyMaterial"));
}
//uint32 UMyMaterialFactory::GetMenuCategories() const
//{
//	return EAssetTypeCategories::Blueprint;
//}