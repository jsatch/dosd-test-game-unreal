// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLevelGM.h"
#include "ConstructorHelpers.h"
#include "TestPlayerController.h"
#include "HeroActor.h"
#include "Engine/World.h"

ATestLevelGM::ATestLevelGM()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<ATestPlayerController> bpPlayerController(
		TEXT("/Game/Blueprints/BP_Test_PlayerController.BP_Test_PlayerController_C")
	);

	static ConstructorHelpers::FClassFinder<AHeroActor> pawnClass(TEXT("/Game/Blueprints/BP_BBTee.BP_BBTee_C"));

	if (pawnClass.Class)
	{ 
		DefaultPawnClass = pawnClass.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No HeroActor class found"));
	}

	PlayerControllerClass = bpPlayerController.Class;

}

void ATestLevelGM::BeginPlay()
{
	/*if (UWorld* const world = GetWorld())
	{
		if (APlayerController* pc = world->GetFirstPlayerController())
		{
			if (InputComponent)
			{
				UE_LOG(LogTemp, Warning, TEXT("Entra aca"));
				InputComponent->BindAxis("Avanzar", this, &ATestLevelGM::avanzar);
			}
		}
	}*/
	Super::BeginPlay();
}

void ATestLevelGM::avanzar(float AxisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("Avanzar: %f"), AxisValue);
}
