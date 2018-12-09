// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TOLContainers.generated.h"


UENUM(BlueprintType)
enum FFactionID
{
	NoFaction,
	Varios,
	Fariven,
	Averon,
	Salidor,
	Seers,
	Beaker,
};

UENUM(BlueprintType)
enum FCharacterType
{
	Lord,
	Lady,
	King,
	Queen,
	Baron,
	Steward,
	Ambassador,
	Rebel,
	GreatLord,
	GreatLady,
	GreatCaptain,
	Hero,
	Mercenary,
};

UENUM(BlueprintType)
enum FLordStance
{
	None,
	Campaigning,
	Training,
	Commerce,
	Governing,
};

UENUM(BlueprintType)
enum FHouseID
{
	NoHouse,
	Orvil,
	Neveral,
	Hereward,
	Oktulis,
	Kaledris,
	Nethanel,
	Darnis,
	Veris,
	Oral,
	Fern,
	Akilis,
	Newham,
	Rainmar,
};

USTRUCT(BlueprintType)
struct FHouseInformation {
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<FHouseID> HouseName;

	UPROPERTY(BlueprintReadWrite)
	FString GlobalReputation;
	UPROPERTY(BlueprintReadWrite)
	int32 Currency;
	UPROPERTY(BlueprintReadWrite)
	int32 Income;
	UPROPERTY(BlueprintReadWrite)
	int32 Expenses;
};

USTRUCT(BlueprintType)
struct FFactionInformation {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<FFactionID> HouseName;
	UPROPERTY(BlueprintReadWrite)
	FString GlobalReputation;
	UPROPERTY(BlueprintReadWrite)
	int32 Currency;
	UPROPERTY(BlueprintReadWrite)
	int32 Income;
	UPROPERTY(BlueprintReadWrite)
	int32 Expenses;
};


USTRUCT(BlueprintType)
struct FCharacterStatistic : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

	#pragma region Constructors

	public:
		FCharacterStatistic() : 
			CharacterID(0),
			CharacterName("NoName"),
			CurrentHouse(FHouseID::NoHouse),
			CurrentFactionReputation(77),
			CurrentHouseReputation(27),
			GlobalReputation(18),
			Currency(5000),
			HonorLevel(6),
			FameLevel(5),
			Income(500),
			Expensives(500),
			CampaignSpeed(5),
			UnitLeadership(3),
			Archery(2),
			CloseCombat(2),
			Cavalry(2),
			UnitSpeed(3),
			Slavery(1),
			Governorship(3),
			Diplomacy(1) {}
		/*
		FCharacterStatistic(int32 InCharacterID,
			TEnumAsByte<FFactionID> InCurrentFaction,
			TEnumAsByte<FHouseID> InCurrentHouse,
			int32 InCurrentFactionReputation,
			int32 InCurrentHouseReputation,
			int32 InGlobalReputation,
			int32 InCurrency,
			int32 InHonorLevel,
			int32 InFameLevel,
			int32 InIncome,
			int32 InExpensives) :
			CharacterID(InCharacterID),
			CurrentFaction(InCurrentFaction),
			CurrentHouse(InCurrentHouse),
			CurrentFactionReputation(InCurrentFactionReputation),
			CurrentHouseReputation(InCurrentHouseReputation),
			GlobalReputation(InGlobalReputation),
			Currency(InCurrency),
			HonorLevel(InHonorLevel),
			FameLevel(InFameLevel),
			Income(InIncome),
			Expensives(InExpensives) {}
			*/
		#pragma endregion

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CharacterID;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CharacterName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<FCharacterType> CharacterType;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<FHouseID> CurrentHouse;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentFactionReputation;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CurrentHouseReputation;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 GlobalReputation;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Currency;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 HonorLevel;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 FameLevel;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Income;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Expensives;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CampaignSpeed;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 UnitLeadership;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Archery;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CloseCombat;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Cavalry;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 UnitSpeed;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Slavery;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Governorship;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Diplomacy;

};

/**
 * Container Script. Can be included for accesssing global structs
 */
class TOL_API TOLContainers
{
public:
	TOLContainers();
	~TOLContainers();
};