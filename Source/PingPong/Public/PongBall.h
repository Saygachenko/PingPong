// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongBall.generated.h"

class UBoxComponent;

UCLASS()
class PINGPONG_API APongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APongBall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Start(); // Logic of the ball movement at the start of the game.
	void Restart(); // Logic of ball movement when restarting the game.
	void GameOver(); // Logic of ball movement at the end of the game.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Ball logic on collision with our PongPlayer.
	UFUNCTION()
	void OnPaddleHit(AActor* OverlappedActor, AActor* OtherActor);

	// Property pointers to components and variable bit bool.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config")
	UStaticMesh* BallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	uint8 bGameover : 1;
};
