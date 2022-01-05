// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Combatant.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main.generated.h"


UENUM(BlueprintType)
enum class EPlayerStatus : uint8
{
	EMS_Movement UMETA(DeplayName = "Movement"),
	EMS_Shoot UMETA(DeplayName = "Shoot"),
	EMS_Attack UMETA(DeplayName = "Attack"),
	EMS_Dodge UMETA(DeplayName = "Dodge"),
	EMS_Skill UMETA(DeplayName = "Skill"),
	EMS_Dash UMETA(DeplayName = "Dash")

};

UENUM(BlueprintType)
enum class EHitElement : uint8
{
	EMS_None UMETA(DeplayName = "None"),
	EMS_RHand UMETA(DeplayName = "RHand"),
	EMS_LHand UMETA(DeplayName = "LHand"),
	EMS_RLeg UMETA(DeplayName = "RLeg"),
	EMS_LLeg UMETA(DeplayName = "LLeg")

};
UENUM(BlueprintType)
enum class EDodgeDirection : uint8
{
	EDD_Left UMETA(DeplayName = "Left"),
	EDD_Right UMETA(DeplayName = "Right"),
	EDD_Back UMETA(DeplayName = "Back")
};

UCLASS()
class STORMCOMBATPROJECT_API AMain : public ACharacter, public ICombatant
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SkillCameraBoom;
	/** Skill camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SkillCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class AEnemy* LockOnObjective;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UBoxComponent* RigthArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* RLeftArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* LeftArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* RigthLegComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* LeftLegComponent;

public:
	// Sets default values for this character's properties
	AMain();
	FTimerHandle DechargeTimer;
	FTimerHandle ChargeTimer;
	FTimerHandle BreakTimer;
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	class UNiagaraSystem* NS_Chacra;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	UNiagaraSystem* NS_Break;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	class UMaterialInstanceConstant* BreakMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	class UMaterialInstanceConstant* InitialMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	class UParticleSystemComponent* specialParticles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	class UParticleSystemComponent* ultimateParticles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	class UAnimMontage* animationMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	class UAnimMontage* dashAnimationMontage;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Status")
	EPlayerStatus playerStatus;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	EHitElement hitElement;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	bool RHandActive;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	bool LHandActive;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	bool RLegActive;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	bool LLegActive;
	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	bool canDamage;
	UFUNCTION()
	virtual bool setDamage_Implementation(float damage) ;
	UFUNCTION(BlueprintCallable)
	void ShootEnd();
	UFUNCTION(BlueprintCallable)
	void CanCombo();
	UFUNCTION(BlueprintCallable)
	void SetHitElement(EHitElement element);
	UFUNCTION(BlueprintCallable)
	void BackToMainCamera();
	FORCEINLINE void SetPlayerStatus(EPlayerStatus status) { playerStatus = status; }
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
	virtual void Jump() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Skills")
		TSubclassOf<class AProyectile> ShurikenToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Skills")
		TSubclassOf<class ASkillBall> SkillToSpawn;
	UFUNCTION()
	virtual void RPunchOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void LPunchOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void RKickBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void LKickBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void UseUltimate();
	UFUNCTION()
	void UseSpecialAttack();
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Main | Sound")
	class USoundCue* FooshSound;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Main | Sound")
	USoundCue* StepSound;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Main | Sound")
	USoundCue* PunchSound;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Main | Sound")
	USoundCue* JumpSound;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Main | Sound")
	USoundCue* LandSound;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Animation | State")
	bool bIsChargingChackra;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Animation | State")
	bool bIsChargingBreak;
	UFUNCTION()
	void HitEnemy(AActor* OtherActor, UPrimitiveComponent* OtherComp);
	UFUNCTION(BlueprintCallable)
	void DodgeEnd();
	UFUNCTION(BlueprintCallable)
	void AttackEnd();
	UFUNCTION(BlueprintCallable)
	void MakeStepSound();
	UFUNCTION(BlueprintCallable)
	void SpawnShuriken();
	UFUNCTION(BlueprintCallable)
	void SpawnFireball();
	UFUNCTION(BlueprintCallable)
	void EndSkillLaunch();
	UFUNCTION(BlueprintCallable)
	void StopDash();
private:
	class UNiagaraComponent* Auxiliar_Effect;
	UNiagaraComponent* Break_Effect;

	bool bIsSpecialCharged;
	bool bIsUltimateCharged;
	bool bIsTransforming;
	float chargingChackraStart;
	float chargingBreakStart;
	float currentChackraChargingTime;
	bool bIsChackraButtonPressed;
	float dechargeTime;
	int comboNumber;
	float skillBoomRotation;
	float forwardInputValue;
	float rightInputValue;
	bool canHit;
	bool isDashing;
	bool dodgeAgain;
	bool bIsTransformed;
	int numAttacksBuffer;
	
	EDodgeDirection dodgeDirection;
	void ChargeBreak();
	void BeginDash();
	void Dodge();
	void DodgeAction();
	void Decharge();
	void StopCharge();
	void SetGameEnemy();
	void LookToEnemy(float deltaTime);
	void ChargeChackra();
	void ChargeSpecial();
	void ChargeUltimate();
	void StopChargeChackra();
	void HandleChackra(float deltaTime);
	void LaunchShuriken();
	void Attack();
	void SelectAttack();
	void LookAtEnemy();
	void LookToOwner();
	void TransformToSpecial();
	void BackToNormalTransformation();
	void DashToEnemy(float DeltaTime);
	void InitSkillCameraMovement();
	void SkillCameraMovement(float deltaTime);
	FVector GetShootSpawnPos();
	FRotator GetLookAtRotationYaw(FVector target);
	
};

