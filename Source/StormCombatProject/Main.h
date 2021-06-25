// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main.generated.h"


UCLASS()
class STORMCOMBATPROJECT_API AMain : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class AEnemy* LockOnObjective;

public:
	// Sets default values for this character's properties
	AMain();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		float chackra;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		float maxChackra;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		float health;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		float maxHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	//class UNiagaraComponent* chargeChacraParticles;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
private:
	
	float bIsChargingChackra;
	void SetGameEnemy();
	void LookToEnemy(float deltaTime);
	void ChargeChackra();
	void StopChargeChackra();
	void HandleChackra(float deltaTime);
	
};

