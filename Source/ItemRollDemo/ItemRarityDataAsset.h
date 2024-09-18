// Copyright Tony Sze 2024

#pragma once

#include "ItemTypes.h"
#include "ItemRarityDataAsset.generated.h"

/**
 * 
 */

USTRUCT()
struct FItemRarityEntry
{
	GENERATED_BODY()

	UPROPERTY(Editanywhere)
	EItemRarity ItemRarity;

	UPROPERTY(EditAnywhere)
	FColor RarityColor;

	UPROPERTY(EditAnywhere)
	float RaritySpawnChance;
};

UCLASS()
class ITEMROLLDEMO_API UItemRarityDataAsset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FItemRarityEntry> RaritySettings;
};
