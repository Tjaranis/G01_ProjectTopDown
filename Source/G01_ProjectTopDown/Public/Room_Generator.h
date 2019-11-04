// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InstancedStaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room_Generator.generated.h"


UCLASS()
class G01_PROJECTTOPDOWN_API ARoom_Generator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoom_Generator();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room_Generator")
		UInstancedStaticMeshComponent* MeshInstances;

	////in meters for width and height, sqaure rooms
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Room_Generator")
		float Size=5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Room_Generator")
		float SquareSize=100;
	////number of random props from prop list
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Room_Generator")
	//	float NumberOfRoomsProps;
	////Number of openings for entrences 
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Room_Generator")
	//	float NumberOfEntrances;
	//
	////TODO function to make entrance
	//AFloor* Floor;
	//AFloor* NorthWall;
	//AFloor* SouthWall;
	//AFloor* EastWall;
	//AFloor* WestWall;

private:

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
