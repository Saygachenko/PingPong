// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "PongPlayer.generated.h"

class UBoxComponent; // Decloration

UCLASS()
class PINGPONG_API APongPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APongPlayer(); // Designer

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Move button bind.

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MovePaddle(float Value); // Y-axis movement logic only.

	UStaticMeshComponent* GetStaticMeshComponent() const // Static mesh getter
	{
		return StaticMeshComponent;
	}

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent; // Pointer to a static grid component

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* BoxComponent; // Pointer to the component cube
};
