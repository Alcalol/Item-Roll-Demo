// Copyright Tony Sze 2024

#pragma once

#include "GameFramework/Actor.h"
#include "ItemTypes.h"
#include "ItemSpawnerButton.generated.h"

class AItemSpawnerPlatform;
class UBoxComponent;
class USceneComponent;

UCLASS()
class ITEMROLLDEMO_API AItemSpawnerButton : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemSpawnerButton();

	void SpawnItems(EItemRarity* ItemRarity, EItemType* ItemType);

protected:

	virtual void BeginPlay() override;

	UPROPERTY()
	USceneComponent* RootSceneComponent;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollider;

	UPROPERTY(EditInstanceOnly)
	TArray<AItemSpawnerPlatform*> ControlledPlatforms;
};
