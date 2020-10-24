// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLevelGM.h"
#include "ConstructorHelpers.h"
#include "TestPlayerController.h"

ATestLevelGM::ATestLevelGM()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<ATestPlayerController> bpPlayerController(
		TEXT("/Game/Blueprints/BP_Test_PlayerController.BP_Test_PlayerController_C")
	);
	PlayerControllerClass = bpPlayerController.Class;
}
