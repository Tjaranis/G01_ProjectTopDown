// Fill out your copyright notice in the Description page of Project Settings.


#include "HumanoidBaseCharacter.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/UnrealMathVectorCommon.h"



// Sets default values
AHumanoidBaseCharacter::AHumanoidBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
		
	//initiated attributes
	BaseTurnRate = 45.0f;
	BaseLookUpAtRate =45.0f;
}

// Called when the game starts or when spawned
void AHumanoidBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHumanoidBaseCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value, true);


		if (Value > 0.0f) {
			const FRotator LeanRotation(-20.0f, GetActorRotation().Yaw, GetActorRotation().Roll);
			const FRotator setLerp = FMath::Lerp(GetActorRotation(), LeanRotation, 0.1f);
			SetActorRotation(setLerp);
		}
		else if (Value < 0.0f) {
			const FRotator LeanRotation(20.0f, GetActorRotation().Yaw, GetActorRotation().Roll);
			const FRotator setLerp = FMath::Lerp(GetActorRotation(), LeanRotation, 0.1f);
			SetActorRotation(setLerp);
		}
	}
	else if (Value == 0.0f) {
		const FRotator LeanRotation(0.0f, GetActorRotation().Yaw, GetActorRotation().Roll);
		const FRotator setLerp = FMath::Lerp(GetActorRotation(), LeanRotation, 0.1f);
		SetActorRotation(setLerp);
	}
}

void AHumanoidBaseCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value, true);
	
		


		if (Value > 0.0f) {
			const FRotator LeanRotationR(GetActorRotation().Pitch, GetActorRotation().Yaw, 20.0f);
			const FRotator setLerp = FMath::Lerp(GetActorRotation(), LeanRotationR, 0.1f);
			SetActorRotation(setLerp);
		}
		else if (Value < 0.0f) {
			const FRotator LeanRotation(GetActorRotation().Pitch, GetActorRotation().Yaw, -20.0f);
			const FRotator setLerp = FMath::Lerp(GetActorRotation(), LeanRotation, 0.1f);
			SetActorRotation(setLerp);
		}
		
	}else if (Value == 0.0f){
		const FRotator LeanRotation(GetActorRotation().Pitch, GetActorRotation().Yaw, 0.0f);
		const FRotator setLerp = FMath::Lerp(GetActorRotation(), LeanRotation, 0.1f);
		SetActorRotation(setLerp);
	}
}

void AHumanoidBaseCharacter::TurnAtRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHumanoidBaseCharacter::LookUpAtRate(float Value)
{
	AddControllerPitchInput(-Value * BaseLookUpAtRate * GetWorld()->GetDeltaSeconds());
}
 
// Called every frame
void AHumanoidBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHumanoidBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHumanoidBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHumanoidBaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnAtRate", this, &AHumanoidBaseCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpAtRate", this, &AHumanoidBaseCharacter::LookUpAtRate);


}

