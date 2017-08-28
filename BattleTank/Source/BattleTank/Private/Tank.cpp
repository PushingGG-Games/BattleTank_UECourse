// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Tank.h"
#include "BattleTank.h"
#include "Engine/World.h"



// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//No need to protect pointers as added at construction
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	//. . .
}