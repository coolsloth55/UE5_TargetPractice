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

}
