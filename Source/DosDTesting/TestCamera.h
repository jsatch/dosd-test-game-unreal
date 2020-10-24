// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "TestCamera.generated.h"

/**
 * 
 */
UCLASS()
class DOSDTESTING_API ATestCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	ATestCamera();
	void UpdateCamera();
private:
	FVector2D GetViewportSize() const;
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Scene Size"))
	FVector2D mSceneSize;
};
