// Copyright Epic Games, Inc. All Rights Reserved.

#include "TargetPracticeGameMode.h"
#include "TargetPracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATargetPracticeGameMode::ATargetPracticeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PrimaryActorTick.bCanEverTick = true;
}

void ATargetPracticeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// update timer
	Update_F_WorldTime();
}

float ATargetPracticeGameMode::Get_F_WorldTime()
{
	return F_WorldTime;
}

void ATargetPracticeGameMode::Set_F_WorldTime(float f)
{
	F_WorldTime = f;
}

void ATargetPracticeGameMode::Update_F_WorldTime()
{
	// get world delta time
	float F_DeltaWorldTime = GetWorld()->DeltaTimeSeconds;

	// add times
	float F_CombinedTime = F_WorldTime + F_DeltaWorldTime;

	// set time
	Set_F_WorldTime(F_CombinedTime);
}