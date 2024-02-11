// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetPracticeActorScoreable.generated.h"

UCLASS()
class TARGETPRACTICE_API ATargetPracticeActorScoreable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetPracticeActorScoreable();

	UPROPERTY(EditDefaultsOnly, Category = "Scoreable Actor")
	bool AllowHitScore = false;

	UPROPERTY(EditDefaultsOnly, Category = "Scoreable Actor")
	bool HasScored = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
