// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HumanoidBaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;


UCLASS()
class G01_PROJECTTOPDOWN_API AHumanoidBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanoidBaseCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	USpringArmComponent* SpringArm1;

	float Speed;
	float Weight;
	float Size;

	//mesh representation
	UStaticMeshComponent Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};