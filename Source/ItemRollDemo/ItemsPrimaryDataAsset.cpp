// Copyright Tony Sze 2024


#include "ItemsPrimaryDataAsset.h"

FPrimaryAssetId UItemsPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId("Item", ItemName);
}