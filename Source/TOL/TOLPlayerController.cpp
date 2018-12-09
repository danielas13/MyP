// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TOLPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "TOLGod.h"
#include "Engine/World.h"

ATOLPlayerController::ATOLPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
/*
//ImplementationFunction of an action that is overriden in BP.
//So this function is never used, but still needs to be here.
void ATOLPlayerController::InterractWithTarget_Implementation(AActor *act)
{
}
*/
void ATOLPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (MyPawn == NULL) {
		MyPawn = GetPawn();
		ControlledCharacter = Cast<ATOLGod>(MyPawn)->PlayerCharacter;
	}

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		float const distance = FVector::Dist(TargetDestination, ControlledCharacter->GetActorLocation());
		if (distance > 130) {
			if (HoldingButtonMovementInput) {
				MoveToMouseCursor();
			}
			else {
				SetNewMoveDestination(TargetDestination);
			}
		}
		else {
			bMoveToMouseCursor = false;
			if (DynamicTarget == true) {
				HoldingButtonMovementInput = false;
				DynamicTarget = false;
				ExecuteInteraction(TargetActor);
			}
		}
	}
}

void ATOLPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATOLPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATOLPlayerController::OnSetDestinationReleased);
}

void ATOLPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATOLPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	//APawn* const MyPawn = GetPawn();
	if (ControlledCharacter)
	{
		//Follow a dynamic target
		if (DynamicTarget == true) {
			TargetDestination = TargetActor->GetActorLocation();
		}
		else {
			TargetDestination = DestLocation;
		}


		float const Distance = FVector::Dist(DestLocation, ControlledCharacter->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 130.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(ControlledCharacter->Controller, DestLocation);
			//FString Str = MyPawn->GetName();
			//UE_LOG(LogTemp, Log, TEXT("This a testing statement. %s"), "Roar");
		}
		else {
			if (DynamicTarget == true) {
				HoldingButtonMovementInput = false;
				DynamicTarget = false;
				bMoveToMouseCursor = false;
				ExecuteInteraction(TargetActor);
				UE_LOG(LogTemp, Log, TEXT("Interact"));
			}
		}
	}
}

void ATOLPlayerController::StopCharacterMovement()
{
	bMoveToMouseCursor = false;
	HoldingButtonMovementInput = false;
	DynamicTarget = false;
	TargetDestination = ControlledCharacter->GetActorLocation();
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(ControlledCharacter->Controller, ControlledCharacter->GetActorLocation());
}

void ATOLPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	if (IsCharacterMovable) {
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		if (Hit.Actor->ActorHasTag(TEXT("Interest"))) {
			if ((FVector::Distance(Cast<AActor>(Hit.Actor)->GetActorLocation(), ControlledCharacter->GetActorLocation())) < 120) {
				TargetActor = Cast<AActor>(Hit.Actor);
				//InterractWithTarget(Cast<AActor>(Hit.Actor));
				HoldingButtonMovementInput = false;
				DynamicTarget = false;
				bMoveToMouseCursor = false;
				ExecuteInteraction(TargetActor);
				UE_LOG(LogTemp, Log, TEXT("StoppingMovementFromPlayerController"));
			}	
			else {
				TargetActor = Cast<AActor>(Hit.Actor);
				TargetDestination = Hit.Actor->GetActorLocation();
				HoldingButtonMovementInput = false;
				DynamicTarget = true;
				bMoveToMouseCursor = true;
			}
			//UE_LOG(LogTemp, Warning, TEXT("DistanceToTarget is %f"), (FVector::Distance(TargetActor->GetActorLocation(), ControlledCharacter->GetActorLocation())));
		}
		else {
			TargetActor = NULL;
			TargetDestination = Hit.ImpactPoint;
			HoldingButtonMovementInput = true;
			DynamicTarget = false;
			bMoveToMouseCursor = true;
		}
	}
}

void ATOLPlayerController::OnSetDestinationReleased()
{
	if (IsCharacterMovable) {
		HoldingButtonMovementInput = false;
	}
}

