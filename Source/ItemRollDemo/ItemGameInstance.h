// Copyright Tony Sze 2024

#pragma once

#include "Engine/GameInstance.h"
#include "ItemRarityDataAsset.h"
#include "ItemGameInstance.generated.h"

class UItemsPrimaryDataAsset;
class UItemAssetLoader;

/**
 * 
 */

UCLASS()
class ITEMROLLDEMO_API UItemGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	const UItemAssetLoader* GetItemAssetLoader() const;

	const UItemRarityDataAsset* GetRarityDataAsset() const;

protected:

	UPROPERTY(BlueprintReadOnly)
	UItemAssetLoader* ItemAssetLoader;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UItemRarityDataAsset* RarityDataAsset;
};
