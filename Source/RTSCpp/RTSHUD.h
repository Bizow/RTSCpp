// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RTSCharacter.h"
#include "RTSHUD.generated.h"

/**
 * 
 */
UCLASS()
class RTSCPP_API ARTSHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override; // Same as Tick()

	UPROPERTY()
	FVector2D InitialPoint;

	UPROPERTY()
	FVector2D CurrentPoint;

	UFUNCTION()
	FVector2D GetMousePosition2D();

	UPROPERTY()
	bool bStartSelecting = false;

	UPROPERTY()
	TArray <ARTSCharacter*> FoundActors;
	
};
