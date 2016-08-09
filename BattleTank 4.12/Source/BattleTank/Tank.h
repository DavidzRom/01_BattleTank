// Copyright ZUB

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// forward declerations
class UTankBarrel; 
class UTankTurret; // Ben doesnt have this
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovement = nullptr;

	

private:
	// Sets default values for this pawn's properties
	ATank();

	




	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSec = 3;

	
	// local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; //TODO REmocve


	double LastFireTime = 0;

};
