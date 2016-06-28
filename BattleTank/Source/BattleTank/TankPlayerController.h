// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	// start tank moving barrel so that a shot would hit where the crosshair intersecss world
	void AimTowardsCrosshair();

	// return at out parameter, true if hit lanscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
