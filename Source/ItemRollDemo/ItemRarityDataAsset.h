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
	int RaritySpawnChance;
};

UCLASS()
class ITEMROLLDEMO_API UItemRarityDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	FColor GetRarityColor(EItemRarity ItemRarity) const;

	EItemRarity GetRandomRarityByWeight(TArray<EItemRarity>& RarityArray) const;

protected:
	UPROPERTY(EditAnywhere)
	TArray<FItemRarityEntry> RaritySettings;
};
