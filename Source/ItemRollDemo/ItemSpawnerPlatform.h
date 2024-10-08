// Copyright Tony Sze 2024

#pragma once

#include "GameFramework/Actor.h"
#include "ItemTypes.h"
#include "ItemSpawnerPlatform.generated.h"

class UItemGameInstance;
class AItemActor;
class USceneComponent;

UCLASS()
class ITEMROLLDEMO_API AItemSpawnerPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemSpawnerPlatform();

	void SpawnNewItem();

	// For blueprint to update any UI that monitors the new item
	UFUNCTION(BlueprintImplementableEvent)
	void ItemSpawnedEvent(const UItemsPrimaryDataAsset* ItemDataAsset);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* ItemSpawnLocator;

	// The default actor to use when spawning a new item.
	UPROPERTY(EditDefaultsOnly, Category = "Item Spawner Settings")
	TSubclassOf<AItemActor> DefaultItemActor;

	// The list rarities allowed to be spawned
	UPROPERTY(EditInstanceOnly, Category = "Item Spawner Settings")
	TArray<EItemRarity> AllowedItemRarities;

	// The list of types of items(slots) allowed to be spawned
	UPROPERTY(EditInstanceOnly, Category = "Item Spawner Settings")
	TArray<EItemType> AllowedItemTypes;

private:
	UPROPERTY()
	UItemGameInstance* GameInstance;

	UPROPERTY()
	AItemActor* CurrentItemActor;
};
