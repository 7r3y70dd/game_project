// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RuneMasterCore : ModuleRules
{
	public RuneMasterCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayTags"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.Add("Slate");
		// PrivateDependencyModuleNames.Add("SlateCore");
	}
}
