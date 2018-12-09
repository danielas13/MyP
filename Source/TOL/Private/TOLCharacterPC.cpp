// Fill out your copyright notice in the Description page of Project Settings.

#include "TOLCharacterPC.h"
#include"Components/StaticMeshComponent.h"

// Sets default values
ATOLCharacterPC::ATOLCharacterPC()
{
	Root = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATOLCharacterPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATOLCharacterPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATOLCharacterPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

