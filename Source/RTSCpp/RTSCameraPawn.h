// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "RTSCameraPawn.generated.h"


UCLASS()
class RTSCPP_API ARTSCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARTSCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	USceneComponent* RootScene;

	UPROPERTY()
	USpringArmComponent* SpringArm;

	UPROPERTY()
	UCameraComponent* Camera;

	UPROPERTY()
	APlayerController* PC;


	UFUNCTION()
	FVector GetCameraPanDirection();

	UPROPERTY()
	float Margin = 15;

	UPROPERTY()
	int32 ScreenSizeX;

	UPROPERTY()
	int32 ScreenSizeY;

	UPROPERTY(EditAnywhere)
	float CamSpeed = 3;

};
