// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetGameStateBase.h"

void ATargetGameStateBase::IncrementScore()
{
	score++;

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Increment Score %d"), score));
	}
}

int ATargetGameStateBase::GetScore()
{
	return score;
}
