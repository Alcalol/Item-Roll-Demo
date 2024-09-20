// Copyright Tony Sze 2024


#include "ItemAssetLoader.h"
#include "ItemsPrimaryDataAsset.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UItemAssetLoader::InitItemAssetLoader()
{
	TArray<FAssetData> AssetDataArray = LoadGameItemsAssetData();

	InsertAssetsToMap(AssetDataArray);
}

UItemsPrimaryDataAsset* UItemAssetLoader::GetRandomItem() const
{
	if (ItemsArray.Num() > 0)
	{
		int ChosenIndex = FMath::RandRange(0, ItemsArray.Num() - 1);

		return ItemsArray[ChosenIndex];
	}
	else
	{
		return nullptr;
	}
}

UItemsPrimaryDataAsset* UItemAssetLoader::GetRandomItem(EItemRarity* ItemRarity, EItemType* ItemType) const
{
	TArray<EItemRarity> RarityArray;
	TArray<EItemType> TypeArray;

	if (ItemRarity)
	{
		RarityArray.Add(*ItemRarity);
	}

	if (ItemType)
	{
		TypeArray.Add(*ItemType);
	}

	TArray<UItemsPrimaryDataAsset*> ItemPool = GetItemsByRarityAndType(RarityArray, TypeArray);

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

const TArray<UItemsPrimaryDataAsset*> UItemAssetLoader::GetItemsByRarity(TArray<EItemRarity>& ItemRarities) const
{
	TArray<EItemType> BlankTypes;
	return GetItemsByRarityAndType(ItemRarities, BlankTypes);
}

const TArray<UItemsPrimaryDataAsset*> UItemAssetLoader::GetItemsByType(TArray<EItemType>& ItemTypes) const
{
	TArray<EItemRarity> BlankRarities;
	return GetItemsByRarityAndType(BlankRarities, ItemTypes);
}

// Accepts blank ItemRarities and ItemTypes, when a specific filter as no entries, assume no filter.
const TArray<UItemsPrimaryDataAsset*> UItemAssetLoader::GetItemsByRarityAndType(TArray<EItemRarity>& ItemRarities, TArray<EItemType>& ItemTypes) const
{
	TArray<UItemsPrimaryDataAsset*> CombinedItemsArray;
	
	CombinedItemsArray = ItemsArray;

	CombinedItemsArray = CombinedItemsArray.FilterByPredicate([&ItemRarities, &ItemTypes](const UItemsPrimaryDataAsset* Item) {
		bool bRarityMatch = false;
		bool bTypeMatch = false;

		if (ItemRarities.Num() > 0)
		{
			for (EItemRarity ItemRarity : ItemRarities)
			{
				if (Item->GetItemRarity() == ItemRarity)
				{
					bRarityMatch = true;
				}
			}
		}
		else
		{
			bRarityMatch = true;
		}

		if (ItemTypes.Num() > 0)
		{
			for (EItemType ItemType : ItemTypes)
			{
				if (Item->GetItemType() == ItemType)
				{
					bTypeMatch = true;
				}
			}
		}
		else
		{
			bTypeMatch = true;
		}

		return (bRarityMatch && bTypeMatch);
	});

	return CombinedItemsArray;
}

const TArray<UItemsPrimaryDataAsset*> UItemAssetLoader::GetAllItems() const
{
	return ItemsArray;
}

// Get all item assets from asset registry
TArray<FAssetData> UItemAssetLoader::LoadGameItemsAssetData()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	TArray<FAssetData> AssetDataArray;
	FARFilter Filter;

	Filter.ClassPaths.Add(UItemsPrimaryDataAsset::StaticClass()->GetClassPathName());

	AssetRegistryModule.Get().GetAssets(Filter, AssetDataArray);

	return AssetDataArray;
}

void UItemAssetLoader::InsertAssetsToMap(TArray<FAssetData>& AssetDataArray)
{
	for (FAssetData AssetDataEntry : AssetDataArray)
	{
		UObject* ObjectToStore = AssetDataEntry.GetAsset();

		UItemsPrimaryDataAsset* ItemDataAsset = Cast<UItemsPrimaryDataAsset>(ObjectToStore);

		EItemRarity ItemRarity = ItemDataAsset->GetItemRarity();
		EItemType ItemType = ItemDataAsset->GetItemType();

		ItemsArray.Add(ItemDataAsset);
	}
}


