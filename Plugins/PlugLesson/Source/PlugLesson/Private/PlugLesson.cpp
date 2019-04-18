// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlugLesson.h"
#include "HAL/IConsoleManager.h"
#include "Editor/UnrealEd/Public/Editor.h"
#include "Editor/ContentBrowser/Public/ContentBrowserModule.h"
#include "Editor/ContentBrowser/Public/IContentBrowserSingleton.h"

#define LOCTEXT_NAMESPACE "FPlugLessonModule"

void FPlugLessonModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FConsoleCommandDelegate Welcoming;
	Welcoming.BindStatic(&FPlugLessonModule::Welcome);
	IConsoleManager::Get().RegisterConsoleCommand(TEXT("ciao"), TEXT("Ti Saluto"), Welcoming);

	FConsoleCommandWithArgsDelegate SuperWelcoming;
	SuperWelcoming.BindStatic(&FPlugLessonModule::SuperWelcome);
	IConsoleManager::Get().RegisterConsoleCommand(TEXT("superciao"), TEXT("Ti Super Saluto"), SuperWelcoming);
}
void FPlugLessonModule::SuperWelcome(const TArray<FString>& Args)
{
	UE_LOG(LogTemp, Warning, TEXT("Super Welcome!!!!"));

	if (Args.Num() < 2)
	{
		return;
	}
	const int32 Count = FCString::Atoi(*Args[0]);
	UClass* ObjectType = FindObject<UClass>(ANY_PACKAGE, *Args[1]);

	if (!ObjectType)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid type %s!!!!"), *Args[1]);
		return;
	}
	if (!ObjectType->IsChildOf<AActor>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid type %s!!!! Does not inherit from AActor"), *Args[1]);
		return;
	}
	if (!GEditor)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Editor found!"));
		return;
	}
	UWorld* const EditorWorld = GEditor->GetEditorWorldContext().World();
	if (!EditorWorld)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Editor World found!"));
		return;
	}
	for (size_t i = 0; i < Count; i++)
	{
		EditorWorld->SpawnActor<AActor>(ObjectType, FTransform::Identity);
	}


	FContentBrowserModule& ContentModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetData> Assets;
	ContentModule.Get().GetSelectedAssets(Assets);

	for (const auto& Asset : Assets)
	{
		UObject* const AssetObject = Asset.GetAsset();
		//Questo per "sporcare" l'asset, verrà considerato come modificato e "salvabile"
		//AssetObject->MarkPackageDirty();
		if (AssetObject->IsA<UBlueprint>())
		{
			UBlueprint* const Blueprint = Cast<UBlueprint>(AssetObject);
			if (Blueprint->GeneratedClass->IsChildOf<AActor>())
			{
				EditorWorld->SpawnActor<AActor>(Blueprint->GeneratedClass, FTransform::Identity);
			}
		}
	}
}
void FPlugLessonModule::Welcome()
{
	UE_LOG(LogTemp, Warning, TEXT("Welcome!!!!"));
	if (GEditor)
	{
		UWorld* EditorWorld = GEditor->GetEditorWorldContext().World();
		if (EditorWorld)
		{
			AActor* Spawned = EditorWorld->SpawnActor<AActor>();
		}
	}
}
void FPlugLessonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlugLessonModule, PlugLesson)