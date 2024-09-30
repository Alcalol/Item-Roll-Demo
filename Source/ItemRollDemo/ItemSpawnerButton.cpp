// Copyright Tony Sze 2024


#include "ItemSpawnerButton.h"
#include "ItemSpawnerPlatform.h"
#include "Components/BoxComponent.h"

// Sets default values
AItemSpawnerButton::AItemSpawnerButton()
{
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>("Root Component");
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));

	RootComponent = RootSceneComponent;
	BoxCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AItemSpawnerButton::BroadcastSpawn()
{
	for (AItemSpawnerPlatform* Platform : ControlledPlatforms)
	{
		if (Platform)
		{
			Platform->SpawnNewItem();
		}
	}
}

// Called when the game starts or when spawned
void AItemSpawnerButton::BeginPlay()
{
	Super::BeginPlay();
}

