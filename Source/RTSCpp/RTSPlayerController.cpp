// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "DrawDebugHelpers.h"
//#include "NavigationSystem.h"

ARTSPlayerController::ARTSPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ARTSPlayerController::BeginPlay()
{
	HUDPtr = Cast<ARTSHUD>(GetHUD());
}

void ARTSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ARTSPlayerController::SelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ARTSPlayerController::SelectionReleased);

	InputComponent->BindAction("RightMouseClick", IE_Released, this, &ARTSPlayerController::MoveReleased);
}

void ARTSPlayerController::SelectionPressed()
{
	if (HUDPtr != nullptr)
	{
		HUDPtr->InitialPoint = HUDPtr->GetMousePosition2D();
		HUDPtr->bStartSelecting = true;
	}
	
}

void ARTSPlayerController::SelectionReleased()
{
	if (HUDPtr != nullptr)
	{
		HUDPtr->bStartSelecting = false;
		SelectedActors = HUDPtr->FoundActors;
	}
}

void ARTSPlayerController::MoveReleased()
{
	if (SelectedActors.Num() > 0)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
		

		for (int32 i = 0; i < SelectedActors.Num(); i++)
		{

			FVector MoveLocation = Hit.Location + FVector(i / 2 * 100, i % 2 * 100, 0);
			DrawDebugSphere(GetWorld(), MoveLocation, 25, 10, FColor::Red, false, 5);
			// Add "AIModule" to D:\UnrealEngine\RTSCpp\Source\RTSCpp\RTSCpp.Build.cs
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(SelectedActors[i]->GetController(), MoveLocation);
			//UNavigationSystemV1::SimpleMoveToLocation(SelectedActors[i]->GetController(), MoveLocation);

		}
	}
}