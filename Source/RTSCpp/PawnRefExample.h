// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnRefExample.generated.h"

UCLASS()
class RTSCPP_API APawnRefExample : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnRefExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/* "&" added to the end of the type makes this a reference
	* and therefore the values passed in are modified and not copied
	*/
	void RefExampleFunction(int32& A, float& B);

	int32 MyInt = 5;

	float MyFloat = 6.5;

};
