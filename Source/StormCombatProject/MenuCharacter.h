// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MenuCharacter.generated.h"

UCLASS()
class STORMCOMBATPROJECT_API AMenuCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMenuCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"), Category = Camera)
	TArray<FVector> markers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	TArray<FString> menuStrings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	FVector currentMarker;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	FString currentString;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	FVector initialPosition;
	int currentStringIndex;
	int currentMarkerIndex;
	void NextMenuStat();
	void PreviousMenuStat();
};
