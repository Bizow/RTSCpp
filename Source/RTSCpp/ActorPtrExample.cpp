// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPtrExample.h"

// Sets default values
AActorPtrExample::AActorPtrExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorPtrExample::BeginPlay()
{
	Super::BeginPlay();

	int32 MyInt;
	int32* ptrToInt;	// create ptr
	int32 MyInt2;

	MyInt = 5;

	MyInt2 = 7;

	ptrToInt = &MyInt;	// assign ptr: ptrToInt = 0x0001567 address of MyInt

	*ptrToInt = 10;		// access ptr: MyInt = 10 

	ptrToInt = &MyInt2; // assign ptr: ptrToInt = 0x0002468 address of MyInt2


	UWorld* OurWorld = GetWorld(); // GetWorld returns a ptr(address) to world

	// "->" = access ptr
	MyPC = OurWorld->GetFirstPlayerController();

	if (MyPC != nullptr) // always safty check ptr's
	{
		MyPC->InitializeComponents();
	}

	/*
	* & Below is a pointer being passed as an argument to BindAction (this is not common)
	* PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlatformerCharacter::OnStartJump);
	*/
	
}

// Called every frame
void AActorPtrExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

