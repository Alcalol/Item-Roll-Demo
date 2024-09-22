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

class UItemGameInstance;

UCLASS()
class ITEMROLLDEMO_API UItemsPrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	EItemType GetItemType() const;

	UFUNCTION(BlueprintCallable)
	FName GetItemName() const;

	UFUNCTION(BlueprintCallable)
	FString GetItemDescription() const;

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetItemImage() const;

	UFUNCTION(BlueprintCallable)
	UStaticMesh* GetItemStaticMesh() const;

	UFUNCTION(BlueprintCallable)
	UMaterialInterface* GetItemMeshMaterial() const;

	UFUNCTION(BlueprintCallable)
	EItemRarity GetItemRarity() const;

	UFUNCTION(BlueprintCallable)
	TArray<FItemRangeEntry> GetItemAllowedEffects() const;

	UFUNCTION(BlueprintCallable)
	int GetItemAllowedEffectsCount() const;

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

	UPROPERTY(EditAnywhere)
	UMaterialInterface* ItemMeshMaterial;

	// The rarity of the item
	UPROPERTY(EditAnywhere)
	EItemRarity ItemRarity;

	// All the effects that can be imbued onto this item
	UPROPERTY(EditAnywhere)
	TArray<FItemRangeEntry> AllowedItemEffects;

	// The number of effects this item can have
	UPROPERTY(EditAnywhere)
	int AllowedEffectsCount;

	UPROPERTY()
	UItemGameInstance* GameInstance;

	FPrimaryAssetId GetPrimaryAssetId() const override;
};
