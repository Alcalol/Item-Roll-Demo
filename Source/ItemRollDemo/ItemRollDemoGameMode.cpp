// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemRollDemoGameMode.h"
#include "ItemRollDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AItemRollDemoGameMode::AItemRollDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
