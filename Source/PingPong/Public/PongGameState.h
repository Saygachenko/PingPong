// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameState.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APongGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	// The function is called on the game server. 
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void RestartGame();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void IncrementScore(int PlayerNumber);

	// Player Scoring Getters.
	int GetPlayerOneScore() const
	{
		return PlayerOneScore;
	}

	int GetPlayerTwoScore() const
	{
		return PlayerOneScore;
	}

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; // Logic for getting points.

	// Replicating Variable Properties.
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Config")
	int PlayerOneScore = 0;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Config")
	int PlayerTwoScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int ScoreToWin = 3;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bGameover = false;

};
