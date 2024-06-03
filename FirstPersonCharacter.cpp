// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HP = 100.f;
}

void AFirstPersonCharacter::OnBeginOverLap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bfromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Damage"))
	{
		HP -= 10.0f;
	}
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFirstPersonCharacter::OnBeginOverLap);

	if (HP_Widget_Class != nullptr) {
		HP_Widget = CreateWidget(GetWorld(), HP_Widget_Class);
		HP_Widget->AddToViewport();
	}
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AFirstPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AFirstPersonCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AFirstPersonCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AFirstPersonCharacter::TurnRate);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AFirstPersonCharacter::LookUpRate);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("StopJump"), EInputEvent::IE_Released, this, &ACharacter::StopJumping);
}

void AFirstPersonCharacter::MoveForward(float AxisValue)
{
	FVector Forward = UKismetMathLibrary::GetForwardVector(GetControlRotation());
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

void AFirstPersonCharacter::MoveRight(float AxisValue)
{
	FVector Right = UKismetMathLibrary::GetRightVector(GetControlRotation());
	AddMovementInput(GetActorRightVector(), AxisValue);
}

void AFirstPersonCharacter::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AFirstPersonCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AFirstPersonCharacter::TurnRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * BaseTurnRate*GetWorld()->GetDeltaSeconds());
}

void AFirstPersonCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}



