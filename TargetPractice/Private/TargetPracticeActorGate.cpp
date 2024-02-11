// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetPracticeActorGate.h"
#include "NiagaraFunctionLibrary.h"
#include "TargetPractice/TargetPracticeCharacter.h"
#include "TargetPracticePlayerState.h"
#include "TargetGameStateBase.h"

// Sets default values
ATargetPracticeActorGate::ATargetPracticeActorGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	ColliderComponent = CreateDefaultSubobject<UBoxComponent>("ColliderComponent");
	
	SetRootComponent(MeshComponent);
	ColliderComponent->SetupAttachment(MeshComponent);

	// setting the following will cause MeshComponent material collison (simple or complex) to not be added.
	//MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	
	// don't need overlap events
	MeshComponent->SetGenerateOverlapEvents(false);
	
	ColliderComponent->SetGenerateOverlapEvents(true);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	ColliderComponent->SetHiddenInGame(bVISDEBUG);

	// set collider scale transform
	ColliderComponent->SetWorldScale3D(FVector(3.0, 1.0, 4.0));

	ColliderComponent->OnComponentBeginOverlap.AddDynamic(
		this, &ATargetPracticeActorGate::OnBeginOverlapComponentEvent
	);
}

void ATargetPracticeActorGate::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATargetPracticeCharacter* Chacacter = Cast<ATargetPracticeCharacter>(OtherActor);

	if (!Reached && Chacacter != nullptr) {
		Reached = true;

		// swap material to dull material indicating reached
		if (MeshComponent != nullptr && GateMaterial != nullptr) {
			MeshComponent->SetMaterial(0, GateMaterial);
		}


		// play niagara system effect
		if (OnGateReachedEffect) {
			FVector Offset = GetActorLocation() * ReachedEffectSpawnOffset;
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, OnGateReachedEffect, Offset);
		}

		// increment score
		if (ATargetGameStateBase* GameState = Cast<ATargetGameStateBase>(GetWorld()->GetGameState()))
		{
			GameState->IncrementScore();
		}

		// increment hit total
		if (APlayerState* State = Chacacter->GetPlayerState()) {
			if (ATargetPracticePlayerState* PlayerState = Cast<ATargetPracticePlayerState>(State)) {
				PlayerState->I_IncrementGateTotal();
			}
		}
	}
}

// Called when the game starts or when spawned
void ATargetPracticeActorGate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetPracticeActorGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

