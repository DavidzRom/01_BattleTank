// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"
// depends on movement component via pathfinding



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	

	
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("TEST"));

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); 

		// aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		// fire if ready
		//GetControlledTank()->Fire();
		ControlledTank->Fire();// TODO Limit firing rate

	}
}

