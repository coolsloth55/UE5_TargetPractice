// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetGameStateBase.h"

void ATargetGameStateBase::IncrementScore()
{
	score++;
}

int ATargetGameStateBase::GetScore()
{
	return score;
}
