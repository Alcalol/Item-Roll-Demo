// Copyright Tony Sze 2024

#pragma once

#include "ItemTypes.h"
#include "ItemAssetLoader.generated.h"

/**
 * Class responsible for the loading and querying of game item assets
 */

class UItemsPrimaryDataAsset;

UCLASS()
class ITEMROLLDEMO_API UItemAssetLoader : public UObject
{
	GENERATED_BODY()
	
public:

	void InitItemAssetLoader();

	const UItemsPrimaryDataAsset* GetRandomItem() const;

	const UItemsPrimaryDataAsset* GetRandomItem(EItemRarity* ItemRarity, EItemType* ItemType) const;

private:

	UPROPERTY()
	TArray<UItemsPrimaryDataAsset*> ItemsArray;

	TArray<FAssetData> LoadGameItemsAssetData();

	void InsertAssetsToMap(TArray<FAssetData>& AssetDataArray);

	const TArray<UItemsPrimaryDataAsset*> GetItemsByRarity(TArray<EItemRarity>& ItemRarities) const;

	const TArray<UItemsPrimaryDataAsset*> GetItemsByType(TArray<EItemType>& ItemTypes) const;

	const TArray<UItemsPrimaryDataAsset*> GetItemsByRarityAndType(TArray<EItemRarity>& ItemRarities, TArray<EItemType>& ItemTypes) const;

	const TArray<UItemsPrimaryDataAsset*> GetAllItems() const;
};
