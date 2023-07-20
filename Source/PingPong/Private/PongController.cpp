// Fill out your copyright notice in the Description page of Project Settings.


#include "PongController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

void APongController::BeginPlay()
{
	Super::BeginPlay();
}

void APongController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

//There should have been a menu button bind.
void APongController::SetupInputComponent()
{
	Super::SetupInputComponent();

	
}

// Here we find the camera on the stage and set it as a view target for the controller.
void APongController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	TArray<AActor*> CameraArray;
	UGameplayStatics::GetAllActorsOfClass(this, ACameraActor::StaticClass(), CameraArray);
	if (CameraArray.Num() > 0)
	{
		SetViewTargetWithBlend(CameraArray[0]);
	}
}
