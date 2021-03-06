// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef STORMCOMBATPROJECT_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define STORMCOMBATPROJECT_Enemy_generated_h

#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_SPARSE_DATA
#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execsetDamage_Implementation);


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execsetDamage_Implementation);


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AEnemy) \
	virtual UObject* _getUObject() const override { return const_cast<AEnemy*>(this); }


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AEnemy) \
	virtual UObject* _getUObject() const override { return const_cast<AEnemy*>(this); }


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public:


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy)


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_PRIVATE_PROPERTY_OFFSET
#define StormCombatProject_Source_StormCombatProject_Enemy_h_10_PROLOG
#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_RPC_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_INCLASS \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Enemy_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_INCLASS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Enemy_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STORMCOMBATPROJECT_API UClass* StaticClass<class AEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StormCombatProject_Source_StormCombatProject_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
