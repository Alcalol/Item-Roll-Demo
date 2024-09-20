// Copyright Tony Sze 2024

#include "ItemRarityDataAsset.h"

FColor UItemRarityDataAsset::GetRarityColor(EItemRarity ItemRarity)
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
