// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StormCombatProject/StormCombatProjectGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStormCombatProjectGameMode() {}
// Cross Module References
	STORMCOMBATPROJECT_API UClass* Z_Construct_UClass_AStormCombatProjectGameMode_NoRegister();
	STORMCOMBATPROJECT_API UClass* Z_Construct_UClass_AStormCombatProjectGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_StormCombatProject();
// End Cross Module References
	void AStormCombatProjectGameMode::StaticRegisterNativesAStormCombatProjectGameMode()
	{
	}
	UClass* Z_Construct_UClass_AStormCombatProjectGameMode_NoRegister()
	{
		return AStormCombatProjectGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AStormCombatProjectGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStormCombatProjectGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_StormCombatProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStormCombatProjectGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "StormCombatProjectGameMode.h" },
		{ "ModuleRelativePath", "StormCombatProjectGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStormCombatProjectGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStormCombatProjectGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStormCombatProjectGameMode_Statics::ClassParams = {
		&AStormCombatProjectGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AStormCombatProjectGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStormCombatProjectGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStormCombatProjectGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStormCombatProjectGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStormCombatProjectGameMode, 2028288783);
	template<> STORMCOMBATPROJECT_API UClass* StaticClass<AStormCombatProjectGameMode>()
	{
		return AStormCombatProjectGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStormCombatProjectGameMode(Z_Construct_UClass_AStormCombatProjectGameMode, &AStormCombatProjectGameMode::StaticClass, TEXT("/Script/StormCombatProject"), TEXT("AStormCombatProjectGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStormCombatProjectGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
