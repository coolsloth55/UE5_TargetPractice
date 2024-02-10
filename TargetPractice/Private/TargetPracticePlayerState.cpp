// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetPracticePlayerState.h"

float ATargetPracticePlayerState::I_GetHitAvg()
{
	if (HitTotal == 0 || FireTotal == 0) {
		return 0.f;
	}

	return ((float)HitTotal / (float)FireTotal) * 100.f;
}

int ATargetPracticePlayerState::I_ComputeScore()
{
	int GateWeight = 2;
	int HitWeight = 1;

	int TmpGate = 1;
	int TmpHit = 1;

	if (HitTotal != 0) {
		TmpHit = HitTotal;
	}

	if (GateTotal == 0) {
		TmpGate = GateTotal;
	}

	return ((GateWeight * TmpGate) + (HitWeight * TmpHit));
}

int ATargetPracticePlayerState::I_GetFireTotal()
{
	return FireTotal;
}

int ATargetPracticePlayerState::I_GetHitTotal()
{
	return HitTotal;
}

int ATargetPracticePlayerState::I_GetGateTotal()
{
	return GateTotal;
}

void ATargetPracticePlayerState::I_IncrementFireTotal()
{
	FireTotal++;
}

void ATargetPracticePlayerState::I_IncrementHitTotal()
{
	HitTotal++;
}

void ATargetPracticePlayerState::I_IncrementGateTotal()
{
	GateTotal++;
}
