// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SY : ModuleRules
{
	public SY(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTasks",
			"GameplayTags",
		});

		PublicIncludePaths.AddRange
		(
			new string[] { "SY", }
		);
	}
}
