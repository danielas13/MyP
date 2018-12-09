// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TOLGameMode.h"
#include "GameFramework/PlayerController.h"
#include "TOLPlayerController.generated.h"

UCLASS()
class ATOLPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATOLPlayerController();
	UPROPERTY(BlueprintReadWrite)
	APawn* MyPawn;
	UPROPERTY(BlueprintReadWrite)
	ACharacter *ControlledCharacter;

	FVector TargetDestination;
	bool DynamicTarget = false;
	UPROPERTY(BlueprintReadWrite)
	AActor *TargetActor;
	UPROPERTY(BlueprintReadWrite)
	bool IsCharacterMovable = true;
	bool HoldingButtonMovementInput = false;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void ExecuteInteraction(AActor *TargetToInteractWith);

	UPROPERTY(BlueprintReadWrite)
	bool bMoveToMouseCursor = false;

	UFUNCTION(BlueprintCallable)
	void StopCharacterMovement();
protected:
	/** True if the controlled character should navigate to the mouse cursor. */


	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface


	#pragma region Movement

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);



	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	

	#pragma endregion


};


