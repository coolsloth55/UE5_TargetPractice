// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TargetPracticeGameMode.generated.h"

UCLASS(minimalapi)
class ATargetPracticeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATargetPracticeGameMode();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "World Timer")
	float Get_F_WorldTime();

	UFUNCTION(BlueprintCallable, Category = "World Timer")
	void  Set_F_WorldTime(float f);

	UFUNCTION(BlueprintCallable, Category = "World Timer")
	void  Update_F_WorldTime();

private:
	float F_WorldTime = 0.0;
};



