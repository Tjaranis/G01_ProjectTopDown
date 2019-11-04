// Fill out your copyright notice in the Description page of Project Settings.

#include "Floor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(
		TEXT("StaticMesh'/Game/MyContent/My_Shape_Cube.My_Shape_Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;
	MeshComponent->SetStaticMesh(Asset);
	
	MeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

