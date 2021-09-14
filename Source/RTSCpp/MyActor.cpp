// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "Components/StaticMeshComponent.h"


/*
In order to delete a C++ class from your project follow the steps below:
Close Visual Studio.
Close UE4 Editor.
Remove the corresponding . cpp and . ...
Remove everything in the folder Binaries.
Right click the . uproject file and click Generate Visual Studio project Files.
Get back to your normal activity.
*/

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(Root);

	LiftAmount = 0.0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	int number = 999;


	/*
	// -> Output Log
	UE_LOG(LogTemp, Warning, TEXT("AMyActor BeginPlay!"));
	UE_LOG(LogTemp, Warning, TEXT("Actor name is: %s %d"), *this->GetName(), number);

	FString sText = FString::Printf(TEXT("Actor name is: %s"), *this->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Actor name is: %s %d"), *sText);

	// -> On Screen
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Screen Message"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *GetActorLocation().ToString()));
	*/

	mCurrentMeshLocation = Mesh->GetRelativeTransform().GetLocation();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	// UE_LOG(LogTemp, Warning, TEXT("%f"), DeltaTime);

	/*

	float distance = this->GetDistanceTo(Player);

	FVector meshLocation = mCurrentMeshLocation;

	if (distance < 250) 
	{
		meshLocation.Z += 80;
	}

	Mesh->SetRelativeLocation(meshLocation);

	*/
}

void AMyActor::LiftCube()
{
	Mesh->AddImpulse(FVector(0, 0, LiftAmount) * Mesh->GetMass());
}


