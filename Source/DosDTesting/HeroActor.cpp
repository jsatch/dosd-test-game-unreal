// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroActor.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"

#define OUT

AHeroActor::AHeroActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//AutoPossessPlayer = EAutoReceiveInput::Player1;
}

void AHeroActor::BeginPlay()
{
	/*if (UWorld* const world = GetWorld())
	{
		if (APlayerController* pc = world->GetFirstPlayerController())
		{
			PossessedBy(pc);

			

			if (InputComponent)
			{
				UE_LOG(LogTemp, Warning, TEXT("Entra aca"));
				InputComponent->BindAxis("Avanzar", this, &AHeroActor::avanzar);
			}
		}
	}*/
	Super::BeginPlay();
}

void AHeroActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector movement = ConsumeMovementInputVector();
	UE_LOG(LogTemp, Warning, TEXT("Mover Adelante: %f %f %f"), movement.X, movement.Y, movement.Z);
	const FVector actualLocation = GetActorLocation();
	const FVector newLocation = actualLocation + (movement * 10.0f);
	SetActorLocation(newLocation);

	
	
}

void AHeroActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Avanzar", this, &AHeroActor::avanzar);
}

void AHeroActor::avanzar(float AxisValue)
{
	if (AxisValue > 0.f)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Mover Adelante: %f"), AxisValue);
		FVector arrowVector(1.f, 0.f, 0.f);
		GetArrowComponent()->GetComponentTransform().TransformPosition(OUT arrowVector);
		//UE_LOG(LogTemp, Warning, TEXT("arrowVector: %f %f %f"), arrowVector.X, arrowVector.Y, arrowVector.Z);
		
		AddMovementInput(arrowVector, AxisValue);
	}
	
}
