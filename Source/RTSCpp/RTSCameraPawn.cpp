// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSCameraPawn.h"

// Sets default values
ARTSCameraPawn::ARTSCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootScene);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-50, 0, 0));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ARTSCameraPawn::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<APlayerController>(GetController());
	PC->GetViewportSize(ScreenSizeX, ScreenSizeY);
}

// Called every frame
void ARTSCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector PanDirection = GetCameraPanDirection();

	if (PanDirection != FVector::ZeroVector)
	{
		AddActorWorldOffset(GetCameraPanDirection() * CamSpeed);
	}
}

// Called to bind functionality to input
void ARTSCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector ARTSCameraPawn::GetCameraPanDirection() 
{
	float MousePosX;
	float MousePosY;
	float CamDirectionX = 0;
	float CamDirectionY = 0;

	PC->GetMousePosition(MousePosX, MousePosY);


	// Left
	if (MousePosX <= Margin)
	{
		CamDirectionY = -1;
	}

	// Right
	if (MousePosX >= ScreenSizeX - Margin)
	{
		CamDirectionY = 1;
	}


	// Top
	if (MousePosY <= Margin)
	{
		CamDirectionX = 1;
	}

	// Bottom
	if (MousePosY >= ScreenSizeY - Margin)
	{
		CamDirectionX = -1;
	}


	return FVector(CamDirectionX, CamDirectionY, 0);

}

