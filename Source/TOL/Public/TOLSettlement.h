// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TOLContainers.h"
#include "Engine/DataTable.h"
#include "TOLSettlement.generated.h"

UENUM(BlueprintType)
enum SettlementType {
	Ruins,
	Outpost,
	Town,
	City,
	Castle,
	Capital,
	Fort,
};

USTRUCT(BlueprintType)
struct FSettlementInfo : public FTableRowBase {
	GENERATED_BODY()

	#pragma region Constructors
	FSettlementInfo() : 
		SettlementID(0),
		SettlementName("NoName"),
		Settlement(SettlementType::Outpost),
		OwningHouse(FHouseID::NoHouse),
		OwnerID(0),
		RangeOfControl(10),
		Income(500),
		Durability(5),
		Prosperity(5){}

	FSettlementInfo(
		int32 InSettlementID,
		FString InSettlementName,
		TEnumAsByte<SettlementType> InSettlement,
		TEnumAsByte<FHouseID> InOwningHouse,
		int32 InOwnerID,
		int32 InRangeOfControl,
		int32 InIncome,
		int32 InDurability) :
		SettlementID(InSettlementID),
		SettlementName(InSettlementName),
		Settlement(InSettlement),
		OwningHouse(InOwningHouse),
		OwnerID(InOwnerID),
		RangeOfControl(InRangeOfControl),
		Income(InIncome),
		Durability(InDurability) {}
	#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 SettlementID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	FString SettlementName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	TEnumAsByte<SettlementType> Settlement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	TEnumAsByte<FHouseID> OwningHouse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 OwnerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 RangeOfControl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 Income;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 Durability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 Prosperity = 5;
}; 
	


UCLASS()
class TOL_API ATOLSettlement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATOLSettlement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	int32 SettlementID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlements")
	FSettlementInfo SettlementInformation;

	USceneComponent * Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent * Mesh;

	UPROPERTY(EditAnywhere)
	bool CanPlayerEnter = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
