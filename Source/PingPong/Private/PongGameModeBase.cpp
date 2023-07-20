// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PongPlayer.h"
#include "PongBall.h"
#include "PongGameHUD.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameModeBase, All, All)

// The logic of starting the game if we have the ball.
void APongGameModeBase::StartGame() const
{
	TArray<AActor*> BallArray;
	UGameplayStatics::GetAllActorsOfClass(this, APongBall::StaticClass(), BallArray);
	if (BallArray.Num() > 0 && IsValid(BallArray[0]))
	{
		Cast<APongBall>(BallArray[0])->Start();
	}
}

// End game logic if we have the ball.
void APongGameModeBase::EndGame()
{
	TArray<AActor*> BallArray;
	UGameplayStatics::GetAllActorsOfClass(this, APongBall::StaticClass(), BallArray);
	if (BallArray.Num() > 0 && IsValid(BallArray[0]))
	{
		Cast<APongBall>(BallArray[0])->GameOver();
	}
}

// Handling the event of a new player entering the game.
void APongGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	TArray<AActor*> PawnArray;
	UGameplayStatics::GetAllActorsOfClass(this, APongPlayer::StaticClass(), PawnArray);
	if (PawnArray.Num() > 0)
	{
		for (AActor* Actor : PawnArray)
		{
			APongPlayer* PongPlayer = Cast<APongPlayer>(Actor);
			if (PongPlayer && !PongPlayer->IsPawnControlled())
			{
				NewPlayer->Possess(PongPlayer);
				PongPlayer->SetOwner(NewPlayer);
			}
		}
	}
	if (GetNumPlayers() == 2)
	{	
		StartGame();
	}
	else
	{
		UE_LOG(LogGameModeBase, Error, TEXT("Stand by for the 2nd player!"));
	}
}

// Handling the event of player's exit from the game.
void APongGameModeBase::Logout(AController* Exiting)
{
	EndGame();

	const auto World = GetWorld();
	if (!World)
	{
		return;
	}

	World->ServerTravel("Game/Maps/Game?listen");
}
