// Copyright Epic Games, Inc. All Rights Reserved.
using System;
using System.IO;
using UnrealBuildTool;

public class StormCombatProject : ModuleRules
{
	public StormCombatProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "AIModule" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });



	}
}
