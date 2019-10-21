// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Humanoid.generated.h"

UCLASS()
class G01_PROJECTTOPDOWN_API AHumanoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHumanoid();
	 
	float Speed;
	float Weight;
	float Size;

	//mesh representation
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
