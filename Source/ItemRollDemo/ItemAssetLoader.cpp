// Copyright Tony Sze 2024


#include "ItemAssetLoader.h"
#include "ItemRarityDataAsset.h"
#include "ItemsPrimaryDataAsset.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UItemAssetLoader::InitItemAssetLoader(const UItemRarityDataAsset& ItemRarityDataAsset)
{
	RarityDataAsset = &ItemRarityDataAsset;

	TArray<FAssetData> AssetDataArray;
	
	LoadGameItemsAssetData(AssetDataArray);

	InsertAssetsToMap(AssetDataArray);
}

const UItemsPrimaryDataAsset* UItemAssetLoader::GetRandomItem() const
{
	if (ItemsArray.Num() > 0)
	{
		TArray<EItemRarity> EmptyRarityList;
		TArray<EItemType> EmptyTypeList;

		// Use the full GetRandomItem function to respect rarity spawn rates.
		return GetRandomItem(EmptyRarityList, EmptyTypeList);
	}
	else
	{
		return nullptr;
	}
}

 const UItemsPrimaryDataAsset* UItemAssetLoader::GetRandomItem(TArray<EItemRarity>& ItemRarityArray, TArray<EItemType>& ItemTypeArray) const
{
	 TArray<UItemsPrimaryDataAsset*> ItemPool;
	 
	 GetItemsByRarityAndType(ItemPool, ItemRarityArray, ItemTypeArray);

	// The returned pool already has chosen weighted rarity rng and type filter, so we can just randomly select one from the result
	if (ItemPool.Num() > 0)
	{
		int ChosenIndex = FMath::RandRange(0, ItemPool.Num() - 1);

		return ItemPool[ChosenIndex];
	}
	else
	{
		return nullptr;
	}
}

// Accepts blank ItemRarities and ItemTypes, when a specific filter as no entries, assume no filter.
void UItemAssetLoader::GetItemsByRarityAndType(TArray<UItemsPrimaryDataAsset*>& OutItemDataAsset, TArray<EItemRarity>& ItemRarities, TArray<EItemType>& ItemTypes) const
{
	// First generate a weighted random rarity from the given TArray
	EItemRarity NewItemRarity = RarityDataAsset->GetRandomRarityByWeight(ItemRarities);

	// Filter out unwanted item types
	OutItemDataAsset = ItemsArray;

	// If ItemType array is populated, also filter by type
	OutItemDataAsset = OutItemDataAsset.FilterByPredicate([&NewItemRarity, &ItemTypes](const UItemsPrimaryDataAsset* Item) {
		bool bRarityMatch = false;
		bool bTypeMatch = false;

		if (Item->GetItemRarity() == NewItemRarity)
		{
			bRarityMatch = true;
		}

		if (ItemTypes.Num() == 0 || (ItemTypes.Num() > 0 && ItemTypes.Contains(Item->GetItemType())))
		{
			bTypeMatch = true;
		}

		return (bRarityMatch && bTypeMatch);
	});
}

void UItemAssetLoader::GetAllItems(TArray<UItemsPrimaryDataAsset*>& OutAllItemsList) const
{
	OutAllItemsList = ItemsArray;
}

// Get all item assets from asset registry
void UItemAssetLoader::LoadGameItemsAssetData(TArray<FAssetData>& OutAssetArray)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	OutAssetArray.Empty();
	FARFilter Filter;

	Filter.ClassPaths.Add(UItemsPrimaryDataAsset::StaticClass()->GetClassPathName());

	AssetRegistryModule.Get().GetAssets(Filter, OutAssetArray);
}

void UItemAssetLoader::InsertAssetsToMap(TArray<FAssetData>& AssetDataArray)
{
	for (FAssetData AssetDataEntry : AssetDataArray)
	{
		UObject* ObjectToStore = AssetDataEntry.GetAsset();

		UItemsPrimaryDataAsset* ItemDataAsset = Cast<UItemsPrimaryDataAsset>(ObjectToStore);

		if (ItemDataAsset)
		{
			EItemRarity ItemRarity = ItemDataAsset->GetItemRarity();
			EItemType ItemType = ItemDataAsset->GetItemType();

			ItemsArray.Add(ItemDataAsset);
		}
	}
}


