// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetPracticeActorGate.h"

// Sets default values
ATargetPracticeActorGate::ATargetPracticeActorGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	ColliderComponent = CreateDefaultSubobject<UBoxComponent>("ColliderComponent");
	

	// worked for overlap
	//SetRootComponent(ColliderComponent);
	//MeshComponent->SetupAttachment(ColliderComponent);

	// working?
	SetRootComponent(MeshComponent);
	ColliderComponent->SetupAttachment(MeshComponent);

	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
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

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("ATargetPracticeActorGate::OnBeginOverlapComponentEvent()"));
	}
}

void ATargetPracticeActorGate::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("ATargetPracticeActorGate::OnBeginOverlapComponentEvent()"));
	}

	if (!Reached) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Reached"));
		}

		Reached = true;
	}

	if (MeshComponent != nullptr) {
		//UMaterial* MaterialAsset = FindObject<UMaterial>(MaterialName);
		//UMaterialInterface* Matieral = ;
		//MeshComponent->SetMaterial(0, Matieral);
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

