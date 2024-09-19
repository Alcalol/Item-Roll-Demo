// Copyright Tony Sze 2024


#include "ItemGameInstance.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UItemGameInstance::Init()
{
	ItemAssetLoader = NewObject<UItemAssetLoader>();

	ItemAssetLoader->InitItemAssetLoader();
}