// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGoal.h"
#include "Components/BoxComponent.h"
#include "PongBall.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameState.h"

// Sets default values
//This is where we attach components and customize them.
APongGoal::APongGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(StaticMeshComponent);
	BoxComponent->SetBoxExtent(FVector(100.0f, 2500.0f, 100.0f));
	BoxComponent->SetCollisionProfileName("Trigger");
}

// This is the logic of the ball crossing an object (goal) and adds points to the player if there was a crossing.
void APongGoal::Score(AActor* OverlappedActorGuid, AActor* OtherActor)
{
	const auto Ball = Cast<APongBall>(OtherActor);
	if (Ball)
	{
		const auto GameState = UGameplayStatics::GetGameState(this);
		if (GameState)
		{
			const auto PongGameState = Cast<APongGameState>(GameState);
			if (PongGameState)
			{
				PongGameState->IncrementScore(PlayerNumber);
			}
		}
	}
}

// Called when the game starts or when spawned
// Here we have a signature on Delegate Score at the beginning of the game.
void APongGoal::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &APongGoal::Score);
}

