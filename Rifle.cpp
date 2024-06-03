// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARifle::Fire()
{
	if (CanFire())
	{
		
		// Decrease rounds in the magazine
		RoundsInMagazine--;
	}
}

void ARifle::Reload()
{
	if (CanReload())
	{
		
		// Refill the magazine to maximum capacity
		RoundsInMagazine = MaxRoundsInMagazine;
	}
}

// Toggle night vision scope
void ARifle::ToggleNightVision()
{
	bNightVisionActive = !bNightVisionActive;
}

bool ARifle::IsNightVisionActive() const
{
	return false;
}

bool ARifle::CanFire() const
{
	return false;
}

bool ARifle::CanReload() const
{
	return false;
}

