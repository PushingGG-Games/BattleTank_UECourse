// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ShellProjectile.generated.h"

UCLASS()
class BATTLETANK_API AShellProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShellProjectile();
	void LaunchShell(float LaunchSpeed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UProjectileMovementComponent *ProjectileMovementComponent = nullptr;

	
};
