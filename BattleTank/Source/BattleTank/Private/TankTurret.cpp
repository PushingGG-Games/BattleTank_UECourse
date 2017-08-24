// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTurret.h"
#include "BattleTank/BattleTank.h"
#include "Engine/World.h"

void UTankTurret::RotateTurret(float DirectionToTurn)
{
	DirectionToTurn = FMath::Clamp<float>(DirectionToTurn, -1, +1);
	auto RotationChange = DirectionToTurn * MaxDegreesPerSecond *GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

