// Fill out your copyright notice in the Description page of Project Settings.


#include "PongWall.h"
#include "Components/BoxComponent.h"

// Sets default values
APongWall::APongWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(StaticMeshComponent);
	BoxComponent->SetBoxExtent(FVector(100.0f, 2500.0f, 100.0f));
	BoxComponent->SetCollisionProfileName("PhysicsActor");

}

// Called when the game starts or when spawned
void APongWall::BeginPlay()
{
	Super::BeginPlay();
	
}