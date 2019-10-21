// Fill out your copyright notice in the Description page of Project Settings.


#include "Humanoid.h"

// Sets default values
AHumanoid::AHumanoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Speed = 10.0f;
	Weight = 80.0f;
	Size = 180.0f;
}

// Called when the game starts or when spawned
void AHumanoid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

