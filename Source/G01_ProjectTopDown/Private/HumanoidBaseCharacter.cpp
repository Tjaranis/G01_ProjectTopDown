// Fill out your copyright notice in the Description page of Project Settings.



#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "HumanoidBaseCharacter.h"


// Sets default values
AHumanoidBaseCharacter::AHumanoidBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
}

void AHumanoidBaseCharacter::MoveRight(float Value)
{
}

void AHumanoidBaseCharacter::TurnAtRate(float Value)
{
}

void AHumanoidBaseCharacter::LookUpAtRate(float Value)
{
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

