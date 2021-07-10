// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Combatant.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class STORMCOMBATPROJECT_API AEnemy : public ACharacter, public ICombatant
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float chackra;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float maxChackra;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float maxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	class UAnimMontage* animationMontage;
	UFUNCTION()
	virtual bool setDamage_Implementation(float damage);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
