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

	void SpawnNewItem(EItemRarity* ItemRarity, EItemType* ItemType);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Item Spawner Settings")
	TSubclassOf<AItemActor> DefaultItemActor;

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* ItemSpawnLocator;

private:
	UPROPERTY()
	UItemGameInstance* GameInstance;

	UPROPERTY()
	AItemActor* CurrentItemActor;
};
