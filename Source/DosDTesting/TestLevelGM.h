// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DosDTestingGameModeBase.h"
#include "TestLevelGM.generated.h"

/**
 * 
 */
UCLASS()
class DOSDTESTING_API ATestLevelGM : public ADosDTestingGameModeBase
{
	GENERATED_BODY()
public:
	ATestLevelGM();

	void BeginPlay() override;

	void avanzar(float AxisValue);
};
