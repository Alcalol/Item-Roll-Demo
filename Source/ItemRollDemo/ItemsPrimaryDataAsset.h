// Copyright Tony Sze 2024

#pragma once

#include "ItemTypes.h"
#include "ItemEffects.h"
#include "Engine/DataAsset.h"
#include "ItemsPrimaryDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FItemRangeEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EItemEffects Effect;

	UPROPERTY(EditAnywhere)
	float MinValue;

	UPROPERTY(EditAnywhere)
	float MaxValue;
};

UCLASS()
class ITEMROLLDEMO_API UItemsPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	const EItemType GetItemType() const;

	UFUNCTION(BlueprintCallable)
	const FName GetItemName() const;

	UFUNCTION(BlueprintCallable)
	const FString GetItemDescription() const;

	UFUNCTION(BlueprintCallable)
	const UTexture2D* GetItemImage() const;

	UFUNCTION(BlueprintCallable)
	const UStaticMesh* GetItemStaticMesh() const;

	UFUNCTION(BlueprintCallable)
	const EItemRarity GetItemRarity() const;

	UFUNCTION(BlueprintCallable)
	const TArray<FItemRangeEntry> GetItemAllowedEffects() const;

	UFUNCTION(BlueprintCallable)
	const int GetItemAllowedEffectsCount() const;

private:

	// The type of item (slot) this is
	UPROPERTY(EditAnywhere)
	EItemType ItemType;

	// The display name of the item
	UPROPERTY(EditAnywhere)
	FName ItemName;

	// The description of the item, shows in tooltip
	UPROPERTY(EditAnywhere)
	FString ItemDescription;

	// The preview image of the item
	UPROPERTY(EditAnywhere)
	UTexture2D* ItemImage;

	// The static mesh for the item
	UPROPERTY(EditAnywhere)
	UStaticMesh* ItemStaticMesh;

	// The rarity of the item
	UPROPERTY(EditAnywhere)
	EItemRarity ItemRarity;

	// All the effects that can be imbued onto this item
	UPROPERTY(EditAnywhere)
	TArray<FItemRangeEntry> AllowedItemEffects;

	// The number of effects this item can have
	UPROPERTY(EditAnywhere)
	int AllowedEffectsCount;

	FPrimaryAssetId GetPrimaryAssetId() const override;
};
