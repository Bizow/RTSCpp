// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeManager.h"
#include "EngineUtils.h"

// Sets default values
ACubeManager::ACubeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubeManager::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* world = GetWorld();

	for (TActorIterator<AMyActor> It(world, AMyActor::StaticClass()); It; ++It)
	{
		AMyActor* actor = *It;
		if (actor != NULL)
		{
			Cubes.Add(actor);
		}
	}

}

// Called every frame
void ACubeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACubeManager::LiftRandomCube(float liftAmount)
{
	int32 countCubes = Cubes.Num();
	if (countCubes == 0)
		return;

	int32 randomNumber = FMath::RandRange(0, countCubes - 1);

	AMyActor* cube = Cubes[randomNumber];
	cube->LiftAmount = liftAmount;
	cube->LiftCube();
}

