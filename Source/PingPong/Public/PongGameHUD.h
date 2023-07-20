// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongGameHUD.generated.h"

class UButton; // Decloration
class UTextBlock; // Decloration

/**
 * 
 */
UCLASS()
class PINGPONG_API UPongGameHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override; // This is where the buttons are initialized, pressed not pressed.
	
	UFUNCTION()
	void RestartGame(); // The function to call Restart the game.

	UFUNCTION()
	void QuitGame(); // There should have been an exit to the menu in this function.

private: 
	// Pointers to the players account, buttons.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = true))
	UTextBlock* PlayerOneScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = true))
	UTextBlock* PlayerTwoScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = true))
	UButton* NoButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = true))
	UButton* YesButton;
};
