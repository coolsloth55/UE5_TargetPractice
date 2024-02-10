// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Timer.h"

float UW_Timer::Get_F_WorldTime()
{
	return F_WorldTime;
}

void UW_Timer::Set_F_WorldTime(float f)
{
	F_WorldTime = f;
}

void UW_Timer::Update_F_WorldTime(float f)
{
	// get world delta time
	float F_DeltaWorldTime = GetWorld()->DeltaTimeSeconds;

	// add times
	float F_CombinedTime = F_WorldTime + F_DeltaWorldTime;

	// set time
	Set_F_WorldTime(F_CombinedTime);

	// convert float to FString
	FString WorldTimeText = FString::Printf(TEXT("%d"), F_CombinedTime);

	// set text
	Timer->SetText(FText::FromString(WorldTimeText));
}
