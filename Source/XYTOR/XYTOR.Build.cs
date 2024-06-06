// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class XYTOR : ModuleRules
{
	public XYTOR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;


        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "AndroidRuntimeSettings", "GameplayTags" });
        PrivateDependencyModuleNames.AddRange(new string[] { "GenericGraphRuntime" });
        
        PublicIncludePaths.AddRange(new[]
        {
	        "XYTOR/Public/Core/Dialogues",
	        "XYTOR/Public/Core/Energy",
	        "XYTOR/Public/Core/Information",
	        "XYTOR/Public/Core/Interaction",
	        "XYTOR/Public/Core/QuestSystem",
	        "XYTOR/Public/Core/Tokens",
	        "XYTOR/Public/Core/WidgetManager"
        });
    }
}
