// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TOLContainers.h"
#include "TOLCharacterPC.generated.h"

UCLASS()
class TOL_API ATOLCharacterPC : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATOLCharacterPC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 CharacterID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	FCharacterStatistic CharacterInformation;

	USceneComponent * Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent * Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
