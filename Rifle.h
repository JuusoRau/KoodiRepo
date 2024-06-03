// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

UCLASS()
class SURVIVAL_API ARifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to fire the gun
	UFUNCTION(BlueprintCallable, Category = "Rifle")
	void Fire();

    // Function to reload the gun
    UFUNCTION(BlueprintCallable, Category = "Rifle")
    void Reload();

    // Function to toggle night vision scope
    UFUNCTION(BlueprintCallable, Category = "Rifle")
    void ToggleNightVision();

    // Check if night vision is active
    UFUNCTION(BlueprintPure, Category = "Rifle")
    bool IsNightVisionActive() const;

private:
    // Number of rounds currently in the magazine
    int32 RoundsInMagazine;

    // Maximum number of rounds in the magazine
    const int32 MaxRoundsInMagazine = 5;

    // Maximum capacity of the gun (total rounds in inventory)
    const int32 MaxCapacity = 30;

    // Flag to track if night vision is active
    bool bNightVisionActive;

    // Function to check if the gun can fire
    bool CanFire() const;

    // Function to check if the gun can reload
    bool CanReload() const;

};
