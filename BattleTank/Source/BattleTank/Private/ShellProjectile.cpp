// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ShellProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"




// Sets default values
AShellProjectile::AShellProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AShellProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShellProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShellProjectile::LaunchShell(float LaunchSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Launching Shell at %f!"), LaunchSpeed);
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	ProjectileMovementComponent->Activate();
}