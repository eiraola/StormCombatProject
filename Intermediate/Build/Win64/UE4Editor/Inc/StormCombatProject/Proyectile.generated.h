// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef STORMCOMBATPROJECT_Proyectile_generated_h
#error "Proyectile.generated.h already included, missing '#pragma once' in Proyectile.h"
#endif
#define STORMCOMBATPROJECT_Proyectile_generated_h

#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_SPARSE_DATA
#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetTarget); \
	DECLARE_FUNCTION(execOnProyectileBeginOverlap);


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetTarget); \
	DECLARE_FUNCTION(execOnProyectileBeginOverlap);


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProyectile(); \
	friend struct Z_Construct_UClass_AProyectile_Statics; \
public: \
	DECLARE_CLASS(AProyectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AProyectile)


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAProyectile(); \
	friend struct Z_Construct_UClass_AProyectile_Statics; \
public: \
	DECLARE_CLASS(AProyectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AProyectile)


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProyectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProyectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProyectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProyectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProyectile(AProyectile&&); \
	NO_API AProyectile(const AProyectile&); \
public:


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProyectile(AProyectile&&); \
	NO_API AProyectile(const AProyectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProyectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProyectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProyectile)


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_PRIVATE_PROPERTY_OFFSET
#define StormCombatProject_Source_StormCombatProject_Proyectile_h_9_PROLOG
#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_RPC_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_INCLASS \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Proyectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_INCLASS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Proyectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STORMCOMBATPROJECT_API UClass* StaticClass<class AProyectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StormCombatProject_Source_StormCombatProject_Proyectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
