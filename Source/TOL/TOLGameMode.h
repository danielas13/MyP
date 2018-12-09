// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TOLSettlement.h"
#include "TOLGameMode.generated.h"


UCLASS(minimalapi)
class ATOLGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	float CurrentTime = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WhenToCheckForUpdates = 20;

	void UpdateWorld();
	void UpdateCharacters();
	void UpdateSettlements();

	TArray<FSettlementInfo> SettlementInfo;
	TArray<ATOLSettlement*> SettlementList;
	//ATOLCharacter *PlayerChar;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	bool IsGameActive;

	UFUNCTION(BlueprintCallable)
	void PauseGameActivity();	//NOTBEINGUSED
	UFUNCTION(BlueprintCallable)
	void StartGameActivity();	//NOTBEINGUSED

	void SetupCharacters();
	void SetupSettlements();

	FSettlementInfo GetSettlementInformation(int32 SettlementID);

	void GetCharacterInformation();//NOTBEINGUSED
	void LoadCharactersFromDatabase();//NOTBEINGUSED

	virtual void Tick(float DeltaSeconds) override;

	ATOLGameMode();
};