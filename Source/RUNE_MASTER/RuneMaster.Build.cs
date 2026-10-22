// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RuneMaster : ModuleRules
{
	public RuneMaster(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"GameplayTags"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"RuneMasterCore",
			"RuneMasterSpells",
			"RuneMasterDungeon"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.Add("Slate");
		// PrivateDependencyModuleNames.Add("SlateCore");

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.AddWithExclusion("OnlineSubsystem", new string[] { "OnlineSubsystemWindows" });
	}
}
