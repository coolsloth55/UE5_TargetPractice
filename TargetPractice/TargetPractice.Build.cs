// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TargetPractice : ModuleRules
{
	public TargetPractice(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
