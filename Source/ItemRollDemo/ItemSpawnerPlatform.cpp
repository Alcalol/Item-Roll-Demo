// Copyright Tony Sze 2024


#include "ItemSpawnerPlatform.h"
#include "ItemGameInstance.h"
#include "ItemAssetLoader.h"
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

void AItemSpawnerPlatform::SpawnNewItem()
{
	if (GameInstance && DefaultItemActor)
	{
		if (CurrentItemActor)
		{
			CurrentItemActor->Destroy();
			CurrentItemActor = nullptr;
		}

		const UItemsPrimaryDataAsset* NewItemDataAsset = GameInstance->GetItemAssetLoader()->GetRandomItem(AllowedItemRarities, AllowedItemTypes);

		if (NewItemDataAsset && ItemSpawnLocator)
		{
			EItemRarity NewRarity = NewItemDataAsset->GetItemRarity();

			const UItemRarityDataAsset* NewRarityAsset = GameInstance->GetRarityDataAsset();
			FColor NewItemRarityColor = NewRarityAsset->GetRarityColor(NewRarity);

			CurrentItemActor = Cast<AItemActor>(GetWorld()->SpawnActor(DefaultItemActor, &ItemSpawnLocator->GetComponentTransform()));

			if (CurrentItemActor)
			{
				CurrentItemActor->ChangeItem(*NewItemDataAsset, NewItemRarityColor);
				ItemSpawnedEvent(NewItemDataAsset);
			}
		}
	}
}

void AItemSpawnerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UItemGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
}

