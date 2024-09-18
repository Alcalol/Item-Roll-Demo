// Copyright Tony Sze 2024

#pragma once

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	RARITY_Common UMETA(DisplayName = "Common"),
	RARITY_Rare UMETA(DisplayName = "Rare"),
	RARITY_Heroic UMETA(DisplayName = "Heroic"),
	RARITY_Legendary UMETA(DisplayName = "Legendary"),
	RARITY_Mythical UMETA(DisplayName = "Mythical")
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	ITEM_Weapon UMETA(DisplayName = "Weapon"),
	ITEM_Amulet UMETA(DisplayName = "Amulet"),
	ITEM_Ring UMETA(DisplayName = "Ring"),
	ITEM_Headgear UMETA(DisplayName = "Headgear"),
	ITEM_Body UMETA(DisplayName = "Body"),
	ITEM_Arms UMETA(DisplayName = "Arms"),
	ITEM_Legs UMETA(DisplayName = "Legs"),
	ITEM_Feet UMETA(DisplayName = "Feet")
};
