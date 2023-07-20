// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PongPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APongPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	bool GetPlayAgain() const // Getter to start the game over again.
	{
		return bPlayAgain;
	}

	// The function is called on the game server. Game restart function.
	UFUNCTION(Server, Reliable)
	void SetPlayAgain(bool bInPlayAgain);
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; // This is where we replicate bPlayAgain.

	// In order for each player to see the current state of the game.
	UPROPERTY(Replicated)
	bool bPlayAgain = false;
};
