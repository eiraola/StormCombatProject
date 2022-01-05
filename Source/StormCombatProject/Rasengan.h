// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rasengan.generated.h"

UCLASS()
class STORMCOMBATPROJECT_API ARasengan : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARasengan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
