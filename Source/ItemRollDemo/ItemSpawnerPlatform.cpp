// Copyright Tony Sze 2024


#include "ItemSpawnerPlatform.h"

// Sets default values
AItemSpawnerPlatform::AItemSpawnerPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemSpawnerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemSpawnerPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

