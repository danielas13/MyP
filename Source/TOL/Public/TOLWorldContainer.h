// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TOLContainers.h"

/**
 * 
 */
class TOL_API TOLWorldContainer
{
public:
	TMap<FHouseID, FHouseInformation> HouseMap;

	void PrintAllHouseContainers();
	
	TOLWorldContainer();
	~TOLWorldContainer();
};
