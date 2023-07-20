// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameState.h"

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

void APongPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APongPlayerState, bPlayAgain)

}
