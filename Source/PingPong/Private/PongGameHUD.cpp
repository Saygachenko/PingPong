// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameHUD.h"
#include "Components/Button.h"
#include "PongPlayerState.h"

// This is where the buttons are initialized, pressed not pressed.
bool UPongGameHUD::Initialize()
{
	bool const bSuccess = Super::Initialize();
	if (!bSuccess)
	{
		return false;
	}

	if (!ensure(NoButton))
	{
		return false;
	}
	NoButton->OnClicked.AddDynamic(this, &UPongGameHUD::QuitGame);

	if (!ensure(YesButton))
	{
		return false;
	}
	YesButton->OnClicked.AddDynamic(this, &UPongGameHUD::RestartGame);

	return true;
}

// The function to call Restart the game.
void UPongGameHUD::RestartGame()
{
	GetOwningPlayer()->GetPlayerState<APongPlayerState>()->SetPlayAgain(true);
}

// There should have been an exit to the menu in this function.
void UPongGameHUD::QuitGame()
{
}
