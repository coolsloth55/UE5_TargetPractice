// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "W_Timer.generated.h"

/**
 * 
 */
UCLASS()
class TARGETPRACTICE_API UW_Timer : public UUserWidget
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, Category = "World Timer")
	float Get_F_WorldTime();
	
	UFUNCTION(BlueprintCallable, Category = "World Timer")
	void  Set_F_WorldTime(float f);

	UFUNCTION(BlueprintCallable, Category = "World Timer")
	void  Update_F_WorldTime(float f);

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Timer;

private:
	float F_WorldTime = 0.0;
};
