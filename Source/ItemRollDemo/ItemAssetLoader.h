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

	void InitItemAssetLoader(UItemGameInstance* CurrentGameInstance, UItemRarityDataAsset* ItemRarityDataAsset);

	UItemsPrimaryDataAsset* GetRandomItem() const;

	UItemsPrimaryDataAsset* GetRandomItem(TArray<EItemRarity>& ItemRarityArray, TArray<EItemType>& ItemTypeArray) const;

private:

	UPROPERTY()
	TArray<UItemsPrimaryDataAsset*> ItemsArray;

	UPROPERTY()
	UItemGameInstance* GameInstance;

	UPROPERTY()
	UItemRarityDataAsset* RarityDataAsset;

	const TArray<UItemsPrimaryDataAsset*> GetItemsByRarityAndType(TArray<EItemRarity>& ItemRarities, TArray<EItemType>& ItemTypes) const;

	const TArray<UItemsPrimaryDataAsset*> GetAllItems() const;

	FColor GetItemRarityColor(EItemRarity ItemRarity);

	TArray<FAssetData> LoadGameItemsAssetData();

	void InsertAssetsToMap(TArray<FAssetData>& AssetDataArray);
};
