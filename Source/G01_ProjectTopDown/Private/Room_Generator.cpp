// Fill out your copyright notice in the Description page of Project Settings.


#include "Room_Generator.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ARoom_Generator::ARoom_Generator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("MeshInstances"));

	RootComponent = MeshInstances;

	/*
	RoomSize = 10;
	NumberOfRoomsProps = RoomSize / 10;
	NumberOfEntrances = 2;

	Floor = CreateDefaultSubobject<AFloor>(FName("Floor"));
	Floor->SetActorRelativeLocation(FVector(0,0,500));

	NorthWall = CreateDefaultSubobject<AFloor>(FName("NorthWall"));
	NorthWall->AttachToActor(Floor,FAttachmentTransformRules::KeepRelativeTransform);

	SouthWall = CreateDefaultSubobject<AFloor>(FName("SouthWall"));
	SouthWall->AttachToActor(Floor, FAttachmentTransformRules::KeepRelativeTransform);

	EastWall = CreateDefaultSubobject<AFloor>(FName("EastWall"));
	EastWall->AttachToActor(Floor, FAttachmentTransformRules::KeepRelativeTransform);

	WestWall = CreateDefaultSubobject<AFloor>(FName("WestWall"));
	WestWall->AttachToActor(Floor, FAttachmentTransformRules::KeepRelativeTransform);
	*/
}



// Called when the game starts or when spawned
void ARoom_Generator::BeginPlay()
{
	Super::BeginPlay();

	//spawn location for the AddIntance
	FTransform InstanceTransform;
	
	//location this spawn at will be relative to the location of the component
	FVector SpawnLocation(0.0f, 0.0f, 0.0f);

	//for InstanceTransform.SetLocation(FVector(0.0f, 0.0f, 0.0f));
	//if no modification to loc is made
	InstanceTransform.SetLocation(SpawnLocation);

	//Adding our instance
	MeshInstances->AddInstance(InstanceTransform);

	for (size_t y = 0; y < Size; y++)
	{
		for (size_t x = 0; x < Size	; x++)
		{
			if (x - y != 0) {
				InstanceTransform.SetLocation(FVector(SquareSize * x, SquareSize * y, 0.0f));
				MeshInstances->AddInstance(InstanceTransform);
			}
		}
	}
}

// Called every frame
void ARoom_Generator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

