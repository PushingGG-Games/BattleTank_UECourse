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
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel *BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UTankAimingComponent *TankAimingComponent = nullptr;


private:	
	ATank();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f; //TODO No clue what the fuck the firing speed should be.
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AShellProjectile> ShellProjectileBlueprint;

	UTankBarrel * Barrel = nullptr;
};
