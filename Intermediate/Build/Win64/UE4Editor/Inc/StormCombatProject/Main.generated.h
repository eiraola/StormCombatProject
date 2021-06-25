// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef STORMCOMBATPROJECT_Main_generated_h
#error "Main.generated.h already included, missing '#pragma once' in Main.h"
#endif
#define STORMCOMBATPROJECT_Main_generated_h

#define StormCombatProject_Source_StormCombatProject_Main_h_13_SPARSE_DATA
#define StormCombatProject_Source_StormCombatProject_Main_h_13_RPC_WRAPPERS
#define StormCombatProject_Source_StormCombatProject_Main_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define StormCombatProject_Source_StormCombatProject_Main_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMain(); \
	friend struct Z_Construct_UClass_AMain_Statics; \
public: \
	DECLARE_CLASS(AMain, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AMain)


#define StormCombatProject_Source_StormCombatProject_Main_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAMain(); \
	friend struct Z_Construct_UClass_AMain_Statics; \
public: \
	DECLARE_CLASS(AMain, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AMain)


#define StormCombatProject_Source_StormCombatProject_Main_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMain(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMain) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMain); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMain); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMain(AMain&&); \
	NO_API AMain(const AMain&); \
public:


#define StormCombatProject_Source_StormCombatProject_Main_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMain(AMain&&); \
	NO_API AMain(const AMain&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMain); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMain); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMain)


#define StormCombatProject_Source_StormCombatProject_Main_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AMain, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AMain, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__LockOnObjective() { return STRUCT_OFFSET(AMain, LockOnObjective); }


#define StormCombatProject_Source_StormCombatProject_Main_h_10_PROLOG
#define StormCombatProject_Source_StormCombatProject_Main_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Main_h_13_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Main_h_13_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Main_h_13_RPC_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Main_h_13_INCLASS \
	StormCombatProject_Source_StormCombatProject_Main_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Main_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Main_h_13_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Main_h_13_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Main_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Main_h_13_INCLASS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Main_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STORMCOMBATPROJECT_API UClass* StaticClass<class AMain>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StormCombatProject_Source_StormCombatProject_Main_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
