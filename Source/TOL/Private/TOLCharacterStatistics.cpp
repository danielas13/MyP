// Fill out your copyright notice in the Description page of Project Settings.

#include "TOLCharacterStatistics.h"

TOLCharacterStatistics::TOLCharacterStatistics()
{
	//CurrentFaction = FFactionID::NoFaction;
	//CurrentHouse = FHouseID::NoHouse;
}

TOLCharacterStatistics::~TOLCharacterStatistics()
{
	CurrentFaction = FFactionID::Averon;
	CurrentHouse = FHouseID::Darnis;
	CurrentFactionReputation = 50;
	CurrentHouseReputation = 20;
	GlobalReputation = 0;
	Currency = 2000;
	HonorLevel = 0;
	FameLevel = 0;
	Income = 500;
	Expensives = 250;
}

TOLCharacterStatistics::TOLCharacterStatistics(FFactionID FID, FHouseID HID, int32 CurrentFR, int32 CurrentHR, int32 GlobalR, int32 Currency, int32 HonorLevel, int32 FameLevel, int32 Income, int32 Expensives)
{
	this->CurrentFaction = FID;
	this->CurrentHouse = HID;
	this->CurrentFactionReputation = CurrentFR;
	this->CurrentHouseReputation = CurrentHR;
	this->GlobalReputation = GlobalR;
	this->Currency = Currency;
	this->HonorLevel = HonorLevel;
	this->FameLevel = FameLevel;
	this->Income = Income;
	this->Expensives = Expensives;
}
