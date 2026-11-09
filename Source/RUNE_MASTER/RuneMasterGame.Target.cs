using UnrealBuildTool;

public class RuneMasterGameTarget : TargetRules
{
    public RuneMasterGameTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.AddRange(new string[] { "RuneMaster" });
    }
}
