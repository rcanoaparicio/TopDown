// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TopDownCPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "TopDownCCharacter.h"
#include "Engine/World.h"

ATopDownCPlayerController::ATopDownCPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	mpPawn = Cast<ATopDownCCharacter>(GetPawn());
	if (mpPawn == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Some message"));
	}
}

void ATopDownCPlayerController::MoveForward(float value)
{
	if (mpPawn == NULL) {
		mpPawn = Cast<ATopDownCCharacter>(GetPawn());
	
		UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
	}
	else mpPawn->AddMovementInput(mpPawn->GetActorForwardVector(), value);
}

void ATopDownCPlayerController::MoveHorizontal(float value)
{
	if (mpPawn == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
	}
	else mpPawn->AddMovementInput(mpPawn->GetActorRightVector(), value);
}

void ATopDownCPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void ATopDownCPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATopDownCPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATopDownCPlayerController::MoveHorizontal);
}

