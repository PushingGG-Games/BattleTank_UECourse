// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


private:
	ATank* GetControlledTank() const;

	//Start tank moving barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

};


