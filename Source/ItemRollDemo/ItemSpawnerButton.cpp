// Copyright Tony Sze 2024


#include "ItemSpawnerButton.h"
#include "ItemSpawnerPlatform.h"
#include "Components/BoxComponent.h"

// Sets default values
AItemSpawnerButton::AItemSpawnerButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>("Root Component");
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));

	RootComponent = RootSceneComponent;
	BoxCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AItemSpawnerButton::SpawnItems(EItemRarity* ItemRarity, EItemType* ItemType)
{
	for (AItemSpawnerPlatform* Platform : ControlledPlatforms)
	{
		Platform->SpawnNewItem(ItemRarity, ItemType);
	}
}

// Called when the game starts or when spawned
void AItemSpawnerButton::BeginPlay()
{
	Super::BeginPlay();
}

