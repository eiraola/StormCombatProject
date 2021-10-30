// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StormCombatProject/Combatant.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatant() {}
// Cross Module References
	STORMCOMBATPROJECT_API UClass* Z_Construct_UClass_UCombatant_NoRegister();
	STORMCOMBATPROJECT_API UClass* Z_Construct_UClass_UCombatant();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_StormCombatProject();
// End Cross Module References
	DEFINE_FUNCTION(ICombatant::execsetDamage)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_damage);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->setDamage_Implementation(Z_Param_damage);
		P_NATIVE_END;
	}
	bool ICombatant::setDamage(float damage)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_setDamage instead.");
		Combatant_eventsetDamage_Parms Parms;
		return Parms.ReturnValue;
	}
	void UCombatant::StaticRegisterNativesUCombatant()
	{
		UClass* Class = UCombatant::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "setDamage", &ICombatant::execsetDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCombatant_setDamage_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UCombatant_setDamage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Combatant_eventsetDamage_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatant_setDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Combatant_eventsetDamage_Parms), &Z_Construct_UFunction_UCombatant_setDamage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatant_setDamage_Statics::NewProp_damage = { "damage", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Combatant_eventsetDamage_Parms, damage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatant_setDamage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatant_setDamage_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatant_setDamage_Statics::NewProp_damage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatant_setDamage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Things" },
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatant_setDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatant, nullptr, "setDamage", nullptr, nullptr, sizeof(Combatant_eventsetDamage_Parms), Z_Construct_UFunction_UCombatant_setDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatant_setDamage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatant_setDamage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatant_setDamage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatant_setDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCombatant_setDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCombatant_NoRegister()
	{
		return UCombatant::StaticClass();
	}
	struct Z_Construct_UClass_UCombatant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCombatant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_StormCombatProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCombatant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombatant_setDamage, "setDamage" }, // 1026039716
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatant_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Combatant.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCombatant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ICombatant>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCombatant_Statics::ClassParams = {
		&UCombatant::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UCombatant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCombatant()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCombatant_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCombatant, 1887750482);
	template<> STORMCOMBATPROJECT_API UClass* StaticClass<UCombatant>()
	{
		return UCombatant::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCombatant(Z_Construct_UClass_UCombatant, &UCombatant::StaticClass, TEXT("/Script/StormCombatProject"), TEXT("UCombatant"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCombatant);
	static FName NAME_UCombatant_setDamage = FName(TEXT("setDamage"));
	bool ICombatant::Execute_setDamage(UObject* O, float damage)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UCombatant::StaticClass()));
		Combatant_eventsetDamage_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UCombatant_setDamage);
		if (Func)
		{
			Parms.damage=damage;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (ICombatant*)(O->GetNativeInterfaceAddress(UCombatant::StaticClass())))
		{
			Parms.ReturnValue = I->setDamage_Implementation(damage);
		}
		return Parms.ReturnValue;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
