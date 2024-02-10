// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TargetPracticePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TARGETPRACTICE_API ATargetPracticePlayerState : public APlayerState
{
	GENERATED_BODY()
	

public:

	// calcs

	UFUNCTION(BlueprintCallable, Category = "Player State")
	float I_GetHitAvg();

	UFUNCTION(BlueprintCallable, Category = "Player State")
	int I_ComputeScore();

	// getters

	UFUNCTION(BlueprintCallable)
	int I_GetFireTotal();

	UFUNCTION(BlueprintCallable)
	int I_GetHitTotal();

	UFUNCTION(BlueprintCallable)
	int I_GetGateTotal();

	// setters

	UFUNCTION(BlueprintCallable)
	void I_IncrementFireTotal();

	UFUNCTION(BlueprintCallable)
	void I_IncrementHitTotal();

	UFUNCTION(BlueprintCallable)
	void I_IncrementGateTotal();

private:

	UPROPERTY()
	int FireTotal = 0;

	UPROPERTY()
	int HitTotal = 0;

	UPROPERTY()
	int GateTotal = 0;

};
