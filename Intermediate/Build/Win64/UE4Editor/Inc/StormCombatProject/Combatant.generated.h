// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef STORMCOMBATPROJECT_Combatant_generated_h
#error "Combatant.generated.h already included, missing '#pragma once' in Combatant.h"
#endif
#define STORMCOMBATPROJECT_Combatant_generated_h

#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_SPARSE_DATA
#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_RPC_WRAPPERS \
	virtual bool setDamage_Implementation(float damage) { return false; }; \
 \
	DECLARE_FUNCTION(execsetDamage);


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool setDamage_Implementation(float damage) { return false; }; \
 \
	DECLARE_FUNCTION(execsetDamage);


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_EVENT_PARMS \
	struct Combatant_eventsetDamage_Parms \
	{ \
		float damage; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		Combatant_eventsetDamage_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_CALLBACK_WRAPPERS
#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	STORMCOMBATPROJECT_API UCombatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCombatant) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(STORMCOMBATPROJECT_API, UCombatant); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatant); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	STORMCOMBATPROJECT_API UCombatant(UCombatant&&); \
	STORMCOMBATPROJECT_API UCombatant(const UCombatant&); \
public:


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	STORMCOMBATPROJECT_API UCombatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	STORMCOMBATPROJECT_API UCombatant(UCombatant&&); \
	STORMCOMBATPROJECT_API UCombatant(const UCombatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(STORMCOMBATPROJECT_API, UCombatant); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatant); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCombatant)


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUCombatant(); \
	friend struct Z_Construct_UClass_UCombatant_Statics; \
public: \
	DECLARE_CLASS(UCombatant, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/StormCombatProject"), STORMCOMBATPROJECT_API) \
	DECLARE_SERIALIZER(UCombatant)


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_GENERATED_UINTERFACE_BODY() \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_GENERATED_UINTERFACE_BODY() \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ICombatant() {} \
public: \
	typedef UCombatant UClassType; \
	typedef ICombatant ThisClass; \
	static bool Execute_setDamage(UObject* O, float damage); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define StormCombatProject_Source_StormCombatProject_Combatant_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~ICombatant() {} \
public: \
	typedef UCombatant UClassType; \
	typedef ICombatant ThisClass; \
	static bool Execute_setDamage(UObject* O, float damage); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define StormCombatProject_Source_StormCombatProject_Combatant_h_10_PROLOG \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_EVENT_PARMS


#define StormCombatProject_Source_StormCombatProject_Combatant_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_RPC_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_CALLBACK_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StormCombatProject_Source_StormCombatProject_Combatant_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_SPARSE_DATA \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_CALLBACK_WRAPPERS \
	StormCombatProject_Source_StormCombatProject_Combatant_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STORMCOMBATPROJECT_API UClass* StaticClass<class UCombatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StormCombatProject_Source_StormCombatProject_Combatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
