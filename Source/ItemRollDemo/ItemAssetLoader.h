// Copyright Tony Sze 2024

#pragma once

#include "ItemTypes.h"
#include "ItemAssetLoader.generated.h"

/**
 * Class responsible for the loading and querying of game item assets
 */

class UItemRarityDataAsset;
class UItemsPrimaryDataAsset;
class UItemGameInstance;

UCLASS()
class ITEMROLLDEMO_API UItemAssetLoader : public UObject
{
	GENERATED_BODY()
	
public:

	void InitItemAssetLoader(const UItemRarityDataAsset& ItemRarityDataAsset);

	const UItemsPrimaryDataAsset* GetRandomItem() const;

	const UItemsPrimaryDataAsset* GetRandomItem(TArray<EItemRarity>& ItemRarityArray, TArray<EItemType>& ItemTypeArray) const;

private:

	UPROPERTY()
	TArray<UItemsPrimaryDataAsset*> ItemsArray;

	UPROPERTY()
	const UItemRarityDataAsset* RarityDataAsset;

	const TArray<UItemsPrimaryDataAsset*> GetItemsByRarityAndType(TArray<EItemRarity>& ItemRarities, TArray<EItemType>& ItemTypes) const;

	const TArray<UItemsPrimaryDataAsset*> GetAllItems() const;

	FColor GetItemRarityColor(EItemRarity ItemRarity);

	void LoadGameItemsAssetData(TArray<FAssetData>& OutAssetArray);

	void InsertAssetsToMap(TArray<FAssetData>& AssetDataArray);
};
