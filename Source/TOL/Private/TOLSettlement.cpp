// Fill out your copyright notice in the Description page of Project Settings.

#include "TOLSettlement.h"
#include"Components/StaticMeshComponent.h"

// Sets default values
ATOLSettlement::ATOLSettlement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Tags.Add("Settlement");
	this->Tags.Add("Interest");

	Root = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);

	//GetWorld()->GetGameState<TOLGameMode>()

	//ATOLGameMode *GameState = GetWorld()->GetGameState<ATOLGameMode>();

	//SettlementInformation = GameState->GetSettlementInformation(this->SettlementID);
}

// Called when the game starts or when spawned
void ATOLSettlement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATOLSettlement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

