// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "Public/Tank.h"
//Depends on Movement component for pathfinding

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ControlledTank = Cast<ATank>(GetPawn());
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		

		if (ensure(PlayerTank))
		{
			//Move towards the player
			MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm

			//Aim towards the player
			ControlledTank->AimAt(PlayerTank->GetActorLocation());

			//Fire if ready
			ControlledTank->Fire(); //TODO limit firing rate
		}
}
