// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Materials/Material.h"
#include "TargetPracticeActorGate.generated.h"

class UNiagaraSystem;

UCLASS()
class TARGETPRACTICE_API ATargetPracticeActorGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetPracticeActorGate();

	UFUNCTION()
	void OnBeginOverlapComponentEvent(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Gate Actor")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Gate Actor")
	TObjectPtr<UBoxComponent> ColliderComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Gate Actor")
	TObjectPtr<UMaterial> GateMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Gate Actor")
	TObjectPtr<UNiagaraSystem> OnGateReachedEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Gate Actor")
	FVector ReachedEffectSpawnOffset = FVector(1.0, 1.0, 4.0);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Gate Actor")
	bool bVISDEBUG;

private:
	bool Reached = false;

};
