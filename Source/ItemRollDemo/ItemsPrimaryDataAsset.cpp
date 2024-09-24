// Copyright Tony Sze 2024


#include "ItemsPrimaryDataAsset.h"
#include "ItemGameInstance.h"
#include "ItemRarityDataAsset.h"

FPrimaryAssetId UItemsPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId("Item", ItemName);
}

EItemType UItemsPrimaryDataAsset::GetItemType() const
{
	return ItemType;
}

const FName& UItemsPrimaryDataAsset::GetItemName() const
{
	return ItemName;
}

const FString& UItemsPrimaryDataAsset::GetItemDescription() const
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

UMaterialInterface* UItemsPrimaryDataAsset::GetItemMeshMaterial() const
{
	return ItemMeshMaterial;
}

EItemRarity UItemsPrimaryDataAsset::GetItemRarity() const
{
	return ItemRarity;
}

const TArray<FItemRangeEntry>& UItemsPrimaryDataAsset::GetItemAllowedEffects() const
{
	return AllowedItemEffects;
}

int UItemsPrimaryDataAsset::GetItemAllowedEffectsCount() const
{
	return AllowedEffectsCount;
}
