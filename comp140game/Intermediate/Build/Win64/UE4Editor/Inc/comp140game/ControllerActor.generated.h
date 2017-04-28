// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMP140GAME_ControllerActor_generated_h
#error "ControllerActor.generated.h already included, missing '#pragma once' in ControllerActor.h"
#endif
#define COMP140GAME_ControllerActor_generated_h

#define comp140game_Source_comp140game_ControllerActor_h_12_RPC_WRAPPERS
#define comp140game_Source_comp140game_ControllerActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define comp140game_Source_comp140game_ControllerActor_h_12_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAControllerActor(); \
	friend COMP140GAME_API class UClass* Z_Construct_UClass_AControllerActor(); \
	public: \
	DECLARE_CLASS(AControllerActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/comp140game"), NO_API) \
	DECLARE_SERIALIZER(AControllerActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define comp140game_Source_comp140game_ControllerActor_h_12_INCLASS \
	private: \
	static void StaticRegisterNativesAControllerActor(); \
	friend COMP140GAME_API class UClass* Z_Construct_UClass_AControllerActor(); \
	public: \
	DECLARE_CLASS(AControllerActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/comp140game"), NO_API) \
	DECLARE_SERIALIZER(AControllerActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define comp140game_Source_comp140game_ControllerActor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AControllerActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AControllerActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AControllerActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AControllerActor); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AControllerActor(const AControllerActor& InCopy); \
public:


#define comp140game_Source_comp140game_ControllerActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AControllerActor(const AControllerActor& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AControllerActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AControllerActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AControllerActor)


#define comp140game_Source_comp140game_ControllerActor_h_9_PROLOG
#define comp140game_Source_comp140game_ControllerActor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	comp140game_Source_comp140game_ControllerActor_h_12_RPC_WRAPPERS \
	comp140game_Source_comp140game_ControllerActor_h_12_INCLASS \
	comp140game_Source_comp140game_ControllerActor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define comp140game_Source_comp140game_ControllerActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	comp140game_Source_comp140game_ControllerActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	comp140game_Source_comp140game_ControllerActor_h_12_INCLASS_NO_PURE_DECLS \
	comp140game_Source_comp140game_ControllerActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID comp140game_Source_comp140game_ControllerActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
