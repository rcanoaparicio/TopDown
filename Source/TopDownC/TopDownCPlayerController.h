// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownCPlayerController.generated.h"

UCLASS()
class ATopDownCPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATopDownCPlayerController();

	void MoveForward(float value);
	void MoveHorizontal(float value);

	UPROPERTY(EditAnywhere)
	class ATopDownCCharacter* mpPawn;

protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	

};


