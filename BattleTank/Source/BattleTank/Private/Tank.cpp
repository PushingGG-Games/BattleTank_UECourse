// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Tank.h"
#include "BattleTank.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankMovementComponent.h"
#include "Public/TankBarrel.h"
#include "Public/ShellProjectile.h"
#include "Engine/World.h"



// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//No need to protect pointers as added at construction
}

// Called to bind functionality to input
void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

		if (Barrel && isReloaded)
		{

			//Spawn a projectile at the socket location on the barrel
			auto Shell = GetWorld()->SpawnActor<AShellProjectile>
				(
					ShellProjectileBlueprint,
					Barrel->GetSocketLocation(FName("Projectile")),
					Barrel->GetSocketRotation(FName("Projectile"))
					);
			Shell->LaunchShell(LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
		}
}