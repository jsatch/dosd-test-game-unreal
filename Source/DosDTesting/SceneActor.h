// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneActor.generated.h"

UCLASS()
class DOSDTESTING_API ASceneActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASceneActor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;
	void SetTileMap(class UPaperTileMap* TileMap);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UPaperTileMapComponent* mTileMapComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "2D Sprites", meta = (DisplayName = "TileMap", AllowPrivateAccess = true))
	class UPaperTileMap* mTileMap;
	

};
