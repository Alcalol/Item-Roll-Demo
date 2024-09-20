// Copyright Tony Sze 2024


#include "ItemsPrimaryDataAsset.h"

FPrimaryAssetId UItemsPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId("Item", ItemName);
}

EItemType UItemsPrimaryDataAsset::GetItemType() const
{
	return ItemType;
}

FName UItemsPrimaryDataAsset::GetItemName() const
{
	return ItemName;
}

FString UItemsPrimaryDataAsset::GetItemDescription() const
{
	return ItemDescription;
}

UTexture2D* UItemsPrimaryDataAsset::GetItemImage() const
{
	return ItemImage;
}

UStaticMesh* UItemsPrimaryDataAsset::GetItemStaticMesh() const
{
	return ItemStaticMesh;
}

EItemRarity UItemsPrimaryDataAsset::GetItemRarity() const
{
	return ItemRarity;
}

TArray<FItemRangeEntry> UItemsPrimaryDataAsset::GetItemAllowedEffects() const
{
	return AllowedItemEffects;
}

int UItemsPrimaryDataAsset::GetItemAllowedEffectsCount() const
{
	return AllowedEffectsCount;
}
