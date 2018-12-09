// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TOLGameMode.h"
#include "TOLPlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
//#include "TOLGod.h"
#include "UObject/ConstructorHelpers.h"

void ATOLGameMode::UpdateWorld()
{
	UpdateCharacters();
	UpdateSettlements();
}

void ATOLGameMode::UpdateCharacters()
{
	/*for (int i = 0; i < CharacterList.Num(); i++) {
		for (int y = 0; y < CharacterStats.Num(); y++) {
			if (CharacterStats[y].CharacterID == CharacterList[i]->CharacterID) {
				CharacterList[i]->CharacterInformation = CharacterStats[y];
			}
		}
	}*/
}

void ATOLGameMode::UpdateSettlements()
{
}

void ATOLGameMode::PauseGameActivity()
{
	IsGameActive = false;
}

void ATOLGameMode::StartGameActivity()
{
	IsGameActive = true;
}

void ATOLGameMode::SetupCharacters()
{
	#pragma region BaseCharacterInformation
	/*
	CharacterStats.Add(FCharacterStatistic(
		9999,		//CharacterID,
		FFactionID::NoFaction,	//FactionID
		FHouseID::Neveral,		//HouseID
		0,		//FactionReputation,
		0,		//HouseReputation,
		0,		//GlobalReputation,
		1500,	//Currency,
		0,		//HonorLevel,
		0,		//FameLevel,
		300,	//income,
		200		//Expensives
	));

	FCharacterStatistic V = FCharacterStatistic(
		1,		//CharacterID,
		FFactionID::NoFaction,	//FactionID
		FHouseID::NoHouse,		//HouseID
		17,		//FactionReputation,
		25,		//HouseReputation,
		17,		//GlobalReputation,
		5000,	//Currency,
		3,		//HonorLevel,
		5,		//FameLevel,
		250,		//income,
		50		//Expensives
	);
	this->CharacterStats.Add(V);

	V = FCharacterStatistic(
		2, //CharacterID,
		FFactionID::NoFaction,
		FHouseID::NoHouse,
		5,		//FactionReputation,
		10,		//HouseReputation,
		20,		//GlobalReputation,
		3000,	//Currency,
		5,		//HonorLevel,
		6,		//FameLevel,
		500,	//income,
		100		//Expensives
	);
	this->CharacterStats.Add(V);
	#pragma endregion
	*/
	/*
	if (CharacterList.Num() == 0) {
		TSubclassOf<ATOLCharacterPC> ClassToFind;
		ClassToFind = ATOLCharacterPC::StaticClass();
		TArray<AActor*> FoundCharacters;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundCharacters);

		for (int i = 0; i < FoundCharacters.Num(); i++) {
			ATOLCharacterPC * Char = Cast<ATOLCharacterPC>(FoundCharacters[i]);
			for (int y = 0; y < CharacterStats.Num(); y++) {
				if (CharacterStats[y].CharacterID == Char->CharacterID) {
					Char->CharacterInformation = CharacterStats[y];
				}
			}
			CharacterList.Add(Char);
		}
	}
	*/

}

void ATOLGameMode::SetupSettlements()
{
	/*
#pragma region Create Settlements
	SettlementInfo.Add(FSettlementInfo(
		0,			//SettlementID,
		"Carion",	//SettlementName,
		SettlementType::Castle, //Settlement,
		FHouseID::NoHouse,		//OwningHouse,
		0,		//OwnerID,
		10,		//RangeOfControl,
		250,	//Income,
		5		//Durability
	));
	SettlementInfo.Add(FSettlementInfo(
		1,			//SettlementID,
		"Seras",	//SettlementName,
		SettlementType::Town, //Settlement,
		FHouseID::NoHouse,		//OwningHouse,
		0,		//OwnerID,
		5,		//RangeOfControl,
		400,	//Income,
		3		//Durability
	));

#pragma endregion

	TSubclassOf<ATOLSettlement> ClassToFind;
	ClassToFind = ATOLSettlement::StaticClass();
	TArray<AActor*> FoundSettlements;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundSettlements);
	UE_LOG(LogTemp, Error, TEXT("Amount of Settlements on file is %d"), FoundSettlements.Num());

	for (int i = 0; i < FoundSettlements.Num(); i++) {
		ATOLSettlement * Sett = Cast<ATOLSettlement>(FoundSettlements[i]);
		for (int y = 0; y < SettlementInfo.Num(); y++) {
			if (SettlementInfo[y].SettlementID == Sett->SettlementID) {
				Sett->SettlementInformation = SettlementInfo[y];
			}
		}
		SettlementList.Add(Sett);  
	}
	*/
}

FSettlementInfo ATOLGameMode::GetSettlementInformation(int32 SettlementID)
{
	/*
	if (SettlementList.Num == 0) {
		SetupSettlements();
	}
	FSettlementInfo sett = FSettlementInfo();
	for (int i = 0; i < SettlementInfo.Num(); i++) {
		if (SettlementInfo[i].SettlementID == SettlementID) {
			sett = SettlementInfo[i];
		}
	}*/
	return FSettlementInfo();
}

void ATOLGameMode::GetCharacterInformation()
{

}

void ATOLGameMode::LoadCharactersFromDatabase()
{
}

void ATOLGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	/*
	if (IsGameActive == true) {
		if (CurrentTime < WhenToCheckForUpdates) {
			CurrentTime = CurrentTime + DeltaSeconds;
			if (CurrentTime >= WhenToCheckForUpdates) {
				CurrentTime = 0;
				UpdateWorld();
				UE_LOG(LogTemp, Log, TEXT("UpdatingWorld"));
			}
		}
	}
	CurrentTime = CurrentTime + DeltaSeconds;*/
}

ATOLGameMode::ATOLGameMode()
{
	// use our custom PlayerController class
	//PlayerControllerClass = ATOLPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MainPlayer/BP_God"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}

/*
	ATOLPlayerController Ctrler = Cast<ATOLPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	PlayerChar = Cast<ATOLGod>(Ctrler.GetPawn())->PlayerCharacter;
	Ctrler.MyPawn = PlayerChar;

	Ctrler.GMode = this; */

	IsGameActive = false;

	//SetupCharacters();
	//SetupSettlements();

	IsGameActive = false;
}