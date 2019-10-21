// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class G01_ProjectTopDownTarget : TargetRules
{
	public G01_ProjectTopDownTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "G01_ProjectTopDown" } );
	}
}
