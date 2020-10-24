// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TestGameInstance.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE(FOnWindowResizedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWindowResizedMultiDelegate);

UCLASS()
class DOSDTESTING_API UTestGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UTestGameInstance();
	void Init() override;
	void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = "Event Binding")
	void ListenWindowResized(FOnWindowResizedDelegate WindowResizedDelegate)
	{
		mOnWindowResizedEvent.Add(WindowResizedDelegate);
	}
private:
	virtual void OnViewportResize(class FViewport* Viewport, uint32 ID);

	UPROPERTY()
	FOnWindowResizedMultiDelegate mOnWindowResizedEvent;

	FDelegateHandle mViewportHandle;
	
};
