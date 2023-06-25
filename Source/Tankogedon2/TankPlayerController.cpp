// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
//#include "TankPawn.h"


ATankPlayerController::ATankPlayerController()
{
	bShowMouseCursor = true;
}

void ATankPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATankPlayerController::MoveForward);
	InputComponent->BindAxis("RotateRight", this, &ATankPlayerController::RotateRight);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ATankPlayerController::Fire);
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	
	FVector MouseDirection;
	DeprojectMousePositionToWorld(MousePos, MouseDirection);
	FVector PawnPos = TankPawn->GetActorLocation();
	MousePos.Z = PawnPos.Z;
	FVector dir = MousePos - PawnPos;
	dir.Normalize();
	MousePos = PawnPos + dir * 1000;
	DrawDebugLine(GetWorld(), PawnPos, MousePos, FColor::Green, false, 0.1f, 0, 5);
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s = StringVariable"), *MousePos.ToString()));

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s = StringVariable"), *TankPawn->GetActorLocation().ToString()));
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	TankPawn = Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::MoveForward(float AxisValue)
{
	TankPawn->MoveForward(AxisValue);
}

void ATankPlayerController::RotateRight(float AxisValue)
{
	TankPawn->RotateRight(AxisValue);
}

void ATankPlayerController::Fire()
{
	TankPawn->Fire();
}
