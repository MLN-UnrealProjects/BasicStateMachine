// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"

UMyObject::UMyObject()
{
	UE_LOG(LogTemp, Warning, TEXT("MyObject constructor called on %p"), this);
}
UMyObject::~UMyObject()
{
	UE_LOG(LogTemp, Error, TEXT("MyObject deconstructor called on %p"), this);
}