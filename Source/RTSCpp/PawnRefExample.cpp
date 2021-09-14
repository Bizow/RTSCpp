// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnRefExample.h"

// Sets default values
APawnRefExample::APawnRefExample()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnRefExample::BeginPlay()
{
	Super::BeginPlay();

	int number = 999;

	int& numberRef = number;

	numberRef = 25; // number = 25

	RefExampleFunction(MyInt, MyFloat);

	// Example UE Usage of Reference
	APlayerController* PC = Cast<APlayerController>(GetController());
	int32 MyScreenX;
	int32 MyScreenY;
	PC->GetViewportSize(MyScreenX, MyScreenY); // modifies variables passed in
	
}

// Called every frame
void APawnRefExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnRefExample::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/* "&" added to the end of the type makes this a reference
* and therefore the values passed in are modified and not copied
*/
void APawnRefExample::RefExampleFunction(int32& A, float& B)
{

}

