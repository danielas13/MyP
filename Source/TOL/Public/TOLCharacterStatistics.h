// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TOLContainers.h"

/**
 * 
 */
class TOL_API TOLCharacterStatistics
{
public:
	
	TOLCharacterStatistics();
	~TOLCharacterStatistics();
	TOLCharacterStatistics(FFactionID FID, FHouseID HID, int32 CurrentFR, int32 CurrentHR, int32 GlobalR,int32 Currency,int32 HonorLevel, int32 FameLevel, int32 Income, int32 Expensives);
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	FFactionID CurrentFaction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	FHouseID CurrentHouse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 CurrentFactionReputation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 CurrentHouseReputation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 GlobalReputation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 Currency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 HonorLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 FameLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 Income;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStatistics")
	int32 Expensives;

};
