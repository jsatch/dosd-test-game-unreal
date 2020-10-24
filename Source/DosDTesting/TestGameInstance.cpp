// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameInstance.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Classes/Engine/World.h"
#include "ConstructorHelpers.h"

UTestGameInstance::UTestGameInstance()
{}

void UTestGameInstance::Init()
{
	Super::Init();
	mViewportHandle = FViewport::ViewportResizedEvent.AddUObject(this, &UTestGameInstance::OnViewportResize);
}

void UTestGameInstance::Shutdown()
{
	FViewport::ViewportResizedEvent.Remove(mViewportHandle);

	Super::Shutdown();
}

void UTestGameInstance::OnViewportResize(FViewport* Viewport, uint32 ID)
{
	mOnWindowResizedEvent.Broadcast();
}
