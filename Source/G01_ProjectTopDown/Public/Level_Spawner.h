// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Level_Spawner.generated.h"

UCLASS()
class G01_PROJECTTOPDOWN_API ALevel_Spawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevel_Spawner();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
		float Distance=50;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
		float DistanceRND=10; 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
		float RotationRND=180;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
		float ScaleRND=1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
		float Size=10;

	void Spawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
