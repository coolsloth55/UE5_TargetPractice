// Copyright Epic Games, Inc. All Rights Reserved.

#include "TargetPracticeProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "TargetPracticeCharacter.h"
#include "TargetPracticePlayerState.h"
#include "TargetPracticeActorScoreable.h"
#include "TargetGameStateBase.h"

ATargetPracticeProjectile::ATargetPracticeProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ATargetPracticeProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 5 seconds by default
	InitialLifeSpan = 5.0f;
}

void ATargetPracticeProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		ATargetPracticeActorScoreable* ScoreableActor = Cast<ATargetPracticeActorScoreable>(OtherActor);

		// increment hit total
		if (Owner != nullptr && ScoreableActor != nullptr && ScoreableActor->AllowHitScore && !ScoreableActor->HasScored)
		{
			ScoreableActor->HasScored = true;

			if (ATargetGameStateBase* gameState = Cast<ATargetGameStateBase>(GetWorld()->GetGameState()))
			{
				gameState->IncrementScore();
			}

			if (ATargetPracticeCharacter* Chacacter = Cast<ATargetPracticeCharacter>(Owner))
			{
				APlayerState* State = Chacacter->GetPlayerState();
				if (State != nullptr) {
					if (ATargetPracticePlayerState* PlayerState = Cast<ATargetPracticePlayerState>(State)) {
						PlayerState->I_IncrementHitTotal();
					}
				}
			}
		}

		// If object is simulating physics apply force
		if ((OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		}

		Destroy();
	}
}