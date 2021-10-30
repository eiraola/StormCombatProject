// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
enum class EHitElement : uint8;
#ifdef STORMCOMBATPROJECT_Main_generated_h
#error "Main.generated.h already included, missing '#pragma once' in Main.h"
#endif
#define STORMCOMBATPROJECT_Main_generated_h

#define StormCombatProject_Source_StormCombatProject_Main_h_42_SPARSE_DATA
#define StormCombatProject_Source_StormCombatProject_Main_h_42_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDodgeEnd); \
	DECLARE_FUNCTION(execHitEnemy); \
	DECLARE_FUNCTION(execLKickBeginOverlap); \
	DECLARE_FUNCTION(execRKickBeginOverlap); \
	DECLARE_FUNCTION(execLPunchOnBeginOverlap); \
	DECLARE_FUNCTION(execRPunchOnBeginOverlap); \
	DECLARE_FUNCTION(execSetHitElement); \
	DECLARE_FUNCTION(execCanCombo); \
	DECLARE_FUNCTION(execShootEnd); \
	DECLARE_FUNCTION(execsetDamage_Implementation);


#define StormCombatProject_Source_StormCombatProject_Main_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDodgeEnd); \
	DECLARE_FUNCTION(execHitEnemy); \
	DECLARE_FUNCTION(execLKickBeginOverlap); \
	DECLARE_FUNCTION(execRKickBeginOverlap); \
	DECLARE_FUNCTION(execLPunchOnBeginOverlap); \
	DECLARE_FUNCTION(execRPunchOnBeginOverlap); \
	DECLARE_FUNCTION(execSetHitElement); \
	DECLARE_FUNCTION(execCanCombo); \
	DECLARE_FUNCTION(execShootEnd); \
	DECLARE_FUNCTION(execsetDamage_Implementation);


#define StormCombatProject_Source_StormCombatProject_Main_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMain(); \
	friend struct Z_Construct_UClass_AMain_Statics; \
public: \
	DECLARE_CLASS(AMain, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AMain) \
	virtual UObject* _getUObject() const override { return const_cast<AMain*>(this); }


#define StormCombatProject_Source_StormCombatProject_Main_h_42_INCLASS \
private: \
	static void StaticRegisterNativesAMain(); \
	friend struct Z_Construct_UClass_AMain_Statics; \
public: \
	DECLARE_CLASS(AMain, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/StormCombatProject"), NO_API) \
	DECLARE_SERIALIZER(AMain) \
	virtual UObject* _getUObject() const override { return const_cast<AMain*>(this); }


#define StormCombatProject_Source_StormCombatProject_Main_h_42_STANDARD_CONSTRUCTORS \
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


#define StormCombatProject_Source_StormCombatProject_Main_h_42_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMain(AMain&&); \
	NO_API AMain(const AMain&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMain); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMain); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMain)


#define StormCombatProject_Source_StormCombatProject_Main_h_42_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AMain, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AMain, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__LockOnObjective() { return STRUCT_OFFSET(AMain, LockOnObjective); } \
	FORCEINLINE static uint32 __PPO__RLeftArmComponent() { return STRUCT_OFFSET(AMain, RLeftArmComponent); } \
	FORCEINLINE static uint32 __PPO__LeftArmComponent() { return STRUCT_OFFSET(AMain, LeftArmComponent); } \
	FORCEINLINE static uint32 __PPO__RigthLegComponent() { return STRUCT_OFFSET(AMain, RigthLegComponent); } \
	FORCEINLINE static uint32 __PPO__LeftLegComponent() { return STRUCT_OFFSET(AMain, LeftLegComponent); }


#define StormCombatProject_Source_StormCombatProject_Main_h_39_PROLOG
#define StormCombatProject_Source_StormCombatProject_Main_h_42_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Main_h_42_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Main_h_42_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Main_h_42_RPC_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Main_h_42_INCLASS \
	StormCombatProject_Source_StormCombatProject_Main_h_42_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Main_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Main_h_42_PRIVATE_PROPERTY_OFFSET \
	StormCombatProject_Source_StormCombatProject_Main_h_42_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Main_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Main_h_42_INCLASS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Main_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STORMCOMBATPROJECT_API UClass* StaticClass<class AMain>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StormCombatProject_Source_StormCombatProject_Main_h


#define FOREACH_ENUM_EDODGEDIRECTION(op) \
	op(EDodgeDirection::EDD_Left) \
	op(EDodgeDirection::EDD_Right) \
	op(EDodgeDirection::EDD_Back) 

enum class EDodgeDirection : uint8;
template<> STORMCOMBATPROJECT_API UEnum* StaticEnum<EDodgeDirection>();

#define FOREACH_ENUM_EHITELEMENT(op) \
	op(EHitElement::EMS_None) \
	op(EHitElement::EMS_RHand) \
	op(EHitElement::EMS_LHand) \
	op(EHitElement::EMS_RLeg) \
	op(EHitElement::EMS_LLeg) 

enum class EHitElement : uint8;
template<> STORMCOMBATPROJECT_API UEnum* StaticEnum<EHitElement>();

#define FOREACH_ENUM_EPLAYERSTATUS(op) \
	op(EPlayerStatus::EMS_Movement) \
	op(EPlayerStatus::EMS_Shoot) \
	op(EPlayerStatus::EMS_Attack) \
	op(EPlayerStatus::EMS_Dodge) 

enum class EPlayerStatus : uint8;
template<> STORMCOMBATPROJECT_API UEnum* StaticEnum<EPlayerStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
