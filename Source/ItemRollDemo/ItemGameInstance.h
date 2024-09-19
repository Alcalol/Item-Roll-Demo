// Copyright Tony Sze 2024

#pragma once

#include "Engine/GameInstance.h"
#include "ItemAssetLoader.h"
#include "ItemGameInstance.generated.h"

class UItemsPrimaryDataAsset;

/**
 * 
 */

UCLASS()
class ITEMROLLDEMO_API UItemGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	UPROPERTY(BlueprintReadOnly)
	UItemAssetLoader* ItemAssetLoader;

};
