// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	void StartGame() const; // The logic of starting the game if we have the ball.
	void EndGame(); // End game logic if we have the ball.

protected:
	virtual void PostLogin(APlayerController* NewPlayer) override; // Handling the event of a new player entering the game.
	virtual void Logout(AController* Exiting) override; // Handling the event of player's exit from the game.

	int ConnetctedPlayers = 0; // Number of players connected by default.
};
