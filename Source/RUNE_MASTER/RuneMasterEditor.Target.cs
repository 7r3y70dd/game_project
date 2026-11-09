using UnrealBuildTool;

public class RuneMasterEditorTarget : TargetRules
{
    public RuneMasterEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.AddRange(new string[] { "RuneMaster" });
    }
}
