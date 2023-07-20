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

void APongController::SetupInputComponent()
{
	Super::SetupInputComponent();

	
}

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
