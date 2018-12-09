// Fill out your copyright notice in the Description page of Project Settings.

#include "TOLWorldContainer.h"

void TOLWorldContainer::PrintAllHouseContainers()
{
	UE_LOG(LogTemp, Warning, TEXT("Your message"));
}

TOLWorldContainer::TOLWorldContainer()
{

	HouseMap.Add(FHouseID::Darnis, FHouseInformation());
}

TOLWorldContainer::~TOLWorldContainer()
{
}
