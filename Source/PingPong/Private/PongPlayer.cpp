// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayer.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
//This is where we attach components and customize them.
APongPlayer::APongPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	GetCapsuleComponent()->SetCollisionProfileName("NoCollision");

	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	GetCharacterMovement()->MaxFlySpeed = 1200.0f;
	GetCharacterMovement()->BrakingDecelerationFlying = 1000.0f;
	GetCharacterMovement()->Mass = 10.0f;
	GetCharacterMovement()->MaxAcceleration = 5000.0f;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetCapsuleComponent());
	StaticMeshComponent->SetCollisionProfileName("PhysicsActor");

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->SetCollisionProfileName("PhysicsActor");
	BoxComponent->SetBoxExtent(FVector(50.0f, 175.0f, 50.0f));
	

}

// Called when the game starts or when spawned
// Enable replication in BeginPlay.
void APongPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	SetReplicateMovement(true);
}

// Called every frame
// In the tick, we get the Player position and set it the frame of movement.
void APongPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Y < -650.0f || GetActorLocation().Y > 650.0f)
	{
		SetActorLocation(FVector(GetActorLocation().X, FMath::Clamp(GetActorLocation().Y, -649.0f, 649.0f), GetActorLocation().Z));
	}
}

// Called to bind functionality to input
// Move button bind.
void APongPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveParties", this, &APongPlayer::MovePaddle);
}

// Y-axis movement logic only.
void APongPlayer::MovePaddle(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value, true);
	}
}

