// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward Declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AShellProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent *TankAimingComponent = nullptr;


private:	
	ATank();
	// Called when the game starts or when spawned
	// Called to bind functionality to input

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AShellProjectile> ShellProjectileBlueprint;


	//TODO Remove once firing method is being refactored
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 7000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	//Local barrel reference for spawning projectile
	UTankBarrel *Barrel = nullptr; //TODO Remove
	double LastFireTime = 0;
};
