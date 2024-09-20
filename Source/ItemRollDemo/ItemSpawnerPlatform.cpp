// Copyright Tony Sze 2024


#include "ItemSpawnerPlatform.h"
#include "ItemGameInstance.h"
#include "ItemActor.h"
#include "ItemsPrimaryDataAsset.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AItemSpawnerPlatform::AItemSpawnerPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	
	ItemSpawnLocator = CreateDefaultSubobject<USceneComponent>(TEXT("Item Spawn Locator"));

	ItemSpawnLocator->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AItemSpawnerPlatform::SpawnNewItem(EItemRarity* ItemRarity, EItemType* ItemType)
{
	if (GameInstance && DefaultItemActor)
	{
		if (CurrentItemActor)
		{
			CurrentItemActor->Destroy();
			CurrentItemActor = nullptr;
		}

		UItemsPrimaryDataAsset* NewItemDataAsset = GameInstance->ItemAssetLoader->GetRandomItem(ItemRarity, ItemType);

		if (NewItemDataAsset && ItemSpawnLocator)
		{
			CurrentItemActor = Cast<AItemActor>(GetWorld()->SpawnActor(DefaultItemActor, &ItemSpawnLocator->GetComponentTransform()));

			if (CurrentItemActor)
			{
				CurrentItemActor->ChangeItem(NewItemDataAsset);
			}
		}
	}
}

// Called when the game starts or when spawned
void AItemSpawnerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UItemGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
}

