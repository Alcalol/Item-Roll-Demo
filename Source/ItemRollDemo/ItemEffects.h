// Copyright Tony Sze 2024

#pragma once

/**
 * A class storing all possible effects that can be imbued onto items.
 * Which effects can be on what specific item types or the buff value range are set in their corrosponding data assets.
 */

UENUM(BlueprintType)
enum class EItemEffects : uint8
{
	EFFECT_Health_Value UMETA(DisplayName = "Health Value"),
	EFFECT_Health_Percent UMETA(DisplayName = "Health %"),
	EFFECT_Damage_Value UMETA(DisplayName = "Damage Value"),
	EFFECT_Damage_Percent UMETA(DisplayName = "Damage %"),
	EFFECT_Strength_Value UMETA(DisplayName = "Strength Value"),
	EFFECT_Strength_Percent UMETA(DisplayName = "Strength %"),
	EFFECT_Dexterity_Value UMETA(DisplayName = "Dexterity Value"),
	EFFECT_Dexterity_Percent UMETA(DisplayName = "Dexterity %"),
	EFFECT_Magic_Value UMETA(DisplayName = "Magic Value"),
	EFFECT_Magic_Percent UMETA(DisplayName = "Magic %"),
	EFFECT_Stamina_Value UMETA(DisplayName = "Stamina Value"),
	EFFECT_Stamina_Percent UMETA(DisplayName = "Stamina %"),
	EFFECT_Damage_Reduction_Value UMETA(DisplayName = "Damage Reduction Value"),
	EFFECT_Damage_Reduction_Percent UMETA(DisplayName = "Damage Reduction %"),
	EFFECT_Armor_Rating_Value UMETA(DisplayName = "Armor Rating Value"),
	EFFECT_Armor_Rating_Percent UMETA(DisplayName = "Armor Rating %"),
	EFFECT_Attack_Speed_Value UMETA(DisplayName = "Attack Speed Value"),
	EFFECT_Attack_Speed_Percent UMETA(DisplayName = "Attack Speed %"),
};
