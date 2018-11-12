// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TopDownCGameMode.h"
#include "TopDownCPlayerController.h"
#include "TopDownCCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDownCGameMode::ATopDownCGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownCPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}