// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameState.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameModeBase.h"
#include "Net/UnrealNetwork.h"
#include "PongPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogPongGameState, All, All);

void APongGameState::RestartGame_Implementation()
{
	int PlayersReady = 0;

	for (auto PlayerState : PlayerArray)
	{
		if (Cast<APongPlayerState>(PlayerState)->GetPlayAgain())
		{
			PlayersReady++;
		}
	}
	if (PlayersReady == 2)
	{
		bGameover = false;
		PlayerOneScore = 0;
		PlayerTwoScore = 0;

		for (auto PlayerState : PlayerArray)
		{
			Cast<APongPlayerState>(PlayerState)->SetPlayAgain(false);
		}

		const auto GameMode = UGameplayStatics::GetGameMode(this);
		if (GameMode)
		{
			const auto PongGameMode = Cast<APongGameModeBase>(GameMode);
			if (PongGameMode)
			{
				PongGameMode->StartGame();
			}
		}
	}
}

void APongGameState::IncrementScore_Implementation(int PlayerNumber)
{
	if (PlayerNumber == 1)
	{
		PlayerOneScore++;
	}
	else if (PlayerNumber == 2)
	{
		PlayerTwoScore++;
	}
	else
	{
		UE_LOG(LogPongGameState, Warning, TEXT("PlayerNumber not set on PongGoal"));
	}

	if (PlayerOneScore == ScoreToWin || PlayerTwoScore == ScoreToWin)
	{
		const auto GameMode = UGameplayStatics::GetGameMode(this);
		if (GameMode)
		{
			const auto PongGameMode = Cast<APongGameModeBase>(GameMode);
			if (PongGameMode)
			{
				bGameover = true;
				PongGameMode->EndGame();
			}
		}
	}

}

void APongGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APongGameState, PlayerOneScore);
	DOREPLIFETIME(APongGameState, PlayerTwoScore);
	DOREPLIFETIME(APongGameState, bGameover);
}
