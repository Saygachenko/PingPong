// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayer.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
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
void APongPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	SetReplicateMovement(true);
}

// Called every frame
void APongPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Y < -650.0f || GetActorLocation().Y > 650.0f)
	{
		SetActorLocation(FVector(GetActorLocation().X, FMath::Clamp(GetActorLocation().Y, -649.0f, 649.0f), GetActorLocation().Z));
	}
}

// Called to bind functionality to input
void APongPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveParties", this, &APongPlayer::MovePaddle);
}

void APongPlayer::MovePaddle(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value, true);
	}
}

