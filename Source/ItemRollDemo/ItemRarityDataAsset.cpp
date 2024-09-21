// Copyright Tony Sze 2024

#include "ItemRarityDataAsset.h"

FColor UItemRarityDataAsset::GetRarityColor(EItemRarity ItemRarity) const
{

	for (FItemRarityEntry RarityEntry : RaritySettings)
	{
		if (RarityEntry.ItemRarity == ItemRarity)
		{
			return RarityEntry.RarityColor;
		}
	}

	return FColor();
}

EItemRarity UItemRarityDataAsset::GetRandomRarityByWeight(TArray<EItemRarity>& RarityArray) const
{
	int CombinedWeight = 0;
	TArray<FItemRarityEntry> SelectedRarities;

	// Filter out unwanted rarities if array is populated
	for (FItemRarityEntry RarityEntry : RaritySettings)
	{
		// Generate an array of allowed rarities and their combined weight
		if (RarityArray.Num() > 0 && !RarityArray.Contains(RarityEntry.ItemRarity))
		{
			continue;
		}

		SelectedRarities.Add(RarityEntry);
		CombinedWeight += RarityEntry.RaritySpawnChance;
	}

	const int Rng = FMath::RandRange(0, CombinedWeight);

	int SearchValue = 0;

	for (FItemRarityEntry RarityEntry : SelectedRarities)
	{
		SearchValue += RarityEntry.RaritySpawnChance;

		if (SearchValue >= Rng)
		{
			return RarityEntry.ItemRarity;
		}
	}

	// Shouldn't be able to reach here, but just incase, return common rarity
	return EItemRarity::RARITY_Common;
}
