// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PongController.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APongController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;
};
