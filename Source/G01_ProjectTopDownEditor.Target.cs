// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class G01_ProjectTopDownEditorTarget : TargetRules
{
	public G01_ProjectTopDownEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "G01_ProjectTopDown" } );
	}
}
