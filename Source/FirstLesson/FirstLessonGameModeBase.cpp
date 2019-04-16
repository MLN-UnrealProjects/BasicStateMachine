// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstLessonGameModeBase.h"
#include "MyPawn.h"
AFirstLessonGameModeBase::AFirstLessonGameModeBase()
{
	DefaultPawnClass = AMyPawn::StaticClass();
}