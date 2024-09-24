// Copyright Tony Sze 2024


#include "ItemGameInstance.h"
#include "ItemAssetLoader.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UItemGameInstance::Init()
{
	ItemAssetLoader = NewObject<UItemAssetLoader>();

	if (RarityDataAsset)
	{
		ItemAssetLoader->InitItemAssetLoader(*RarityDataAsset);
	}
}

const UItemAssetLoader* UItemGameInstance::GetItemAssetLoader() const
{
	return ItemAssetLoader;
}

const UItemRarityDataAsset* UItemGameInstance::GetRarityDataAsset() const
{
	return RarityDataAsset;
}
