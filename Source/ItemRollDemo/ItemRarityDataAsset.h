// Copyright Tony Sze 2024

#pragma once

#include "ItemTypes.h"
#include "ItemRarityDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
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

public:
	FColor GetRarityColor(EItemRarity ItemRarity);

private:
	UPROPERTY(EditAnywhere)
	TArray<FItemRarityEntry> RaritySettings;
};
