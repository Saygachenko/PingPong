// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongGoal.generated.h"

class UBoxComponent; // Decloration

UCLASS()
class PINGPONG_API APongGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APongGoal();

	UFUNCTION()
	void Score(AActor* OverlappedActorGuid, AActor* OtherActor);// This is the logic of the ball crossing an object(goal) and adds points to the player if there was a crossing.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; // Here we have a signature on Delegate Score at the beginning of the game.

	// Pointers to components and the variable number of players.

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int PlayerNumber = 0;
};
