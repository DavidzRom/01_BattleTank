// Copyright ZUB


#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	

	// no need to protect pointers as added at consruction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovement = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
	

}



void ATank::BeginPlay()
{
	Super::BeginPlay(); // needed for blueprint beginplay to run!!!!
	
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();

}



void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	
	
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSec;

	if (isReloaded) 
	{

		// spawn projectile at socket location on barrel

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}