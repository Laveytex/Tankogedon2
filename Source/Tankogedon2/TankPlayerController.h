// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPawn.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATankPawn;

UCLASS()
class TANKOGEDON2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
	ATankPawn* TankPawn;
	UPROPERTY()
	FVector MousePos;
	
	
public:
	ATankPlayerController();
	virtual void SetupInputComponent() override;
	FVector GetMousePos(){return  MousePos;}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void MoveForward(float Value);
	void RotateRight(float Value);
	void Fire();
};

