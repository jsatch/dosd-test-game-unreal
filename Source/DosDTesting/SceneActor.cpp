// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneActor.h"
#include "PaperTileMapComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
ASceneActor::ASceneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mTileMapComponent = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("LevelTileMap"));

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> tmapMat(TEXT("/Paper2D/TranslucentUnlitSpriteMaterial"));
	mTileMapComponent->SetMaterial(0, tmapMat.Object);

	RootComponent = mTileMapComponent;

}

// Called when the game starts or when spawned
void ASceneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASceneActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (mTileMapComponent->TileMap)
	{
		mTileMapComponent->SetTileMap(mTileMap);
	}
}

// Called every frame
void ASceneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASceneActor::SetTileMap(UPaperTileMap* TileMap)
{
	mTileMap = TileMap;
	mTileMapComponent->SetTileMap(TileMap);
}

