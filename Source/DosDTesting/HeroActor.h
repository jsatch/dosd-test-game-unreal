// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "HeroActor.generated.h"

/**
 * 
 */
UCLASS()
class DOSDTESTING_API AHeroActor : public APaperCharacter
{
	GENERATED_BODY()
public:
	AHeroActor();
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void avanzar(float AxisValue);
	
};
