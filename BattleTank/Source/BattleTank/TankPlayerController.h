// Copyright Vici Videogames

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;
class UTankAimingComponent;
/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void Constructed(UTankAimingComponent *AimCompRef, ATank *TankRef);

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



	//Start tank moving barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	//return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333f;
};


