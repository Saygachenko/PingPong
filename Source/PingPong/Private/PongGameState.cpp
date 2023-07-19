// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameState.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(LogPongGameState, All, All);

void APongGameState::RestartGame()
{
	int PlayersReady{};

	for (auto PlayerState : PlayerArray)
	{

	}
}

void APongGameState::IncrementScore(int PlayerNumber)
{
	if (PlayerNumber == 1)
	{
		PlayerNumber++;
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

}
