// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;

private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	//virtual void Tick(float DeltaSeconds) override;
	
	// start tank moving barrel so that a shot would hit where the crosshair intersecss world
	void AimTowardsCrosshair();

	// return at out parameter, true if hit lanscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;


	UPROPERTY(EditAnywhere, Category = "Screen Dimensions")
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Screen Dimensions")
	float CrossHairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
