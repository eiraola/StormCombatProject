// Copyright Epic Games, Inc. All Rights Reserved.

#include "StormCombatProjectGameMode.h"
#include "StormCombatProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStormCombatProjectGameMode::AStormCombatProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
