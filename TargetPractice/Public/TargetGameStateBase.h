// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TargetGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TARGETPRACTICE_API ATargetGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void IncrementScore();

	UFUNCTION(BlueprintCallable)
	int GetScore();


protected:

	UPROPERTY(EditDefaultsOnly, Category = "Target Practice")
	int score = 0;
	
};
