// Copyright Tony Sze 2024


#include "ItemsPrimaryDataAsset.h"

FPrimaryAssetId UItemsPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId("Item", ItemName);
}

const EItemType UItemsPrimaryDataAsset::GetItemType() const
{
	return ItemType;
}

const FName UItemsPrimaryDataAsset::GetItemName() const
{
	return ItemName;
}

const FString UItemsPrimaryDataAsset::GetItemDescription() const
{
	return ItemDescription;
}

const UTexture2D* UItemsPrimaryDataAsset::GetItemImage() const
{
	return ItemImage;
}

const UStaticMesh* UItemsPrimaryDataAsset::GetItemStaticMesh() const
{
	return ItemStaticMesh;
}

const EItemRarity UItemsPrimaryDataAsset::GetItemRarity() const
{
	return ItemRarity;
}

const TArray<FItemRangeEntry> UItemsPrimaryDataAsset::GetItemAllowedEffects() const
{
	return AllowedItemEffects;
}

const int UItemsPrimaryDataAsset::GetItemAllowedEffectsCount() const
{
	return AllowedEffectsCount;
}
