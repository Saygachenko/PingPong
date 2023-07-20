// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameState.h"

// There's a logic to restarting the game.
void APongPlayerState::SetPlayAgain_Implementation(bool bInPlayAgain)
{
	bPlayAgain = bInPlayAgain;

	const auto GameState = UGameplayStatics::GetGameState(this);
	if (GameState)
	{
		const auto PongGameState = Cast<APongGameState>(GameState);
		if (PongGameState)
		{
			PongGameState->RestartGame();
		}
	}
}

// This is where we replicate bPlayAgain.
void APongPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APongPlayerState, bPlayAgain)

}
