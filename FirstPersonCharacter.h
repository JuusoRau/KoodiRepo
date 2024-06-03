// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class SURVIVAL_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HP;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> HP_Widget_Class;
	UUserWidget* HP_Widget;

	UFUNCTION()
	void OnBeginOverLap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult);
	

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Movement inputs
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);


	//Mouse inputs
	void Turn(float AxisValue);
	void LookUp(float AxisValue);

	//Gamepad Look Inputs
	void TurnRate(float AxisValue);
	void LookUpRate(float AxisValue);
	
	UPROPERTY(EditAnywhere)
	float BaseTurnRate = 45.f;

	UPROPERTY(EditAnywhere)
	float BaseLookUpRate = 45.f;
};
