// Fill out your copyright notice in the Description page of Project Settings.


#include "Level_Spawner.h"
#include "Engine/World.h"
#include <Floor.h>

// Sets default values
ALevel_Spawner::ALevel_Spawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void ALevel_Spawner::Spawn()
{
	float roomSize = 22.f;
	float offset = roomSize *50.f;
	float wallTickness = 0.5;
	
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AFloor* FloorActor = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), FVector(0, 0, 0), FRotator(0, 0, 0), SpawnInfo);
	FloorActor->SetActorScale3D(FVector(roomSize, roomSize, 0.5));
	
	AFloor* NorthWall = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), FVector(0, offset, 0), FRotator(0, 0, 0), SpawnInfo);
	NorthWall->SetActorScale3D(FVector(roomSize, wallTickness, 5));
	
	AFloor* EastWall = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), FVector(offset, 0, 0), FRotator(0, 0, 0), SpawnInfo);
	EastWall->SetActorScale3D(FVector(wallTickness, roomSize, 5));

	AFloor* WestWall = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), FVector(0, -offset, 0), FRotator(0, 0, 0), SpawnInfo);
	WestWall->SetActorScale3D(FVector(roomSize, wallTickness, 5));

	AFloor* SouthWall = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), FVector(-offset, 0, 0), FRotator(0, 0, 0), SpawnInfo);
	SouthWall->SetActorScale3D(FVector(wallTickness, roomSize, 5));

	NorthWall->AttachToActor(FloorActor, FAttachmentTransformRules::KeepWorldTransform);
	EastWall->AttachToActor(FloorActor, FAttachmentTransformRules::KeepWorldTransform); 
	WestWall->AttachToActor(FloorActor, FAttachmentTransformRules::KeepWorldTransform);
	SouthWall->AttachToActor(FloorActor, FAttachmentTransformRules::KeepWorldTransform);


	FloorActor->SetActorLocation(FVector(1000, -400, 0));
}

// Called when the game starts or when spawned
void ALevel_Spawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

// Called every frame
void ALevel_Spawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
}

