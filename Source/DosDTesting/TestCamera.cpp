// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCamera.h"
#include "Engine.h"

#define OUT

ATestCamera::ATestCamera()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent->bVisible = false;
	RootComponent->bHiddenInGame = true;

	mSceneSize = FVector2D(160.f, 160.f);

	GetCameraComponent()->SetProjectionMode(ECameraProjectionMode::Orthographic);
	GetCameraComponent()->SetOrthoWidth(160.f);
	GetCameraComponent()->bConstrainAspectRatio = false;
}

void ATestCamera::UpdateCamera()
{
	const FVector2D viewportSize = GetViewportSize();
	const float Width = mSceneSize.X;
	const float Height = mSceneSize.Y;

	const float s1 = Width / viewportSize.X;
	const float s2 = Height / viewportSize.Y;

	GetCameraComponent()->OrthoWidth = s1 < s2 ? viewportSize.X * s2 : Width;
}

FVector2D ATestCamera::GetViewportSize() const
{
	FVector2D size;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(OUT size);
	}
	return size;
}

void ATestCamera::BeginPlay()
{
	UpdateCamera();
	Super::BeginPlay();
}
