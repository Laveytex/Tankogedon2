// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "TankPawn.generated.h"

class UStaticMeshComponent;
class UCameraComponent;
class USpringArmComponent;
class ATankPlayerController;
class ACannon;

UCLASS()
class TANKOGEDON2_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();

protected:
	// Called when the game starts or when spawned
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Component")
	UStaticMeshComponent* BodyMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Component")
	UStaticMeshComponent* TurretMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Component")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Component")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UArrowComponent * CannonSetupPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret|Cannon")
	TSubclassOf<ACannon> CannonClass;

	UPROPERTY()
	ACannon * Cannon;

	UPROPERTY()
	ATankPlayerController* TankController;
	
public:
	void MoveForward(float AxisVelue);
	void RotateRight(float AxisVelue);

	UFUNCTION()
	void Fire();


protected:
	void MoveForwardAdd(float DeltaTime);
	void RotateRightAdd(float DeltaTime);
	
	void RotateTurretTo(FVector TargetPosition);
	
	void SetupCannon();


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Movement")
	float MoveSpeed = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Movement")
	float RotationSpeed = 100.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Movement|Tank Speed")
	float InterpolationKey = 0.1f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Movement|Turret Speed")
	float TurretRotationInterpolationKey = 0.5f;

	float TargetForwardAxisValue = 0.0f;
	float TargetRightAxisValue = 0.0f;
	float CurrentRightAxisValue;

};


