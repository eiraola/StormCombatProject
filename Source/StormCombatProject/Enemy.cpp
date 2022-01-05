// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Animation/AnimMontage.h"
#include "Math/UnrealMathUtility.h"
// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	maxHealth = 100;
	health = maxHealth;
	maxChackra = 100;
	chackra = maxChackra / 2;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AEnemy::setDamage_Implementation(float damage) {
	health = health - damage;
	
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	UE_LOG(LogTemp, Warning, TEXT("Ouch"));
	if (animInstance) {
		UE_LOG(LogTemp, Warning, TEXT("Ouch"));
		if (animationMontage) {
			UE_LOG(LogTemp, Warning, TEXT("Ouch2"));
			animInstance->Montage_Play(animationMontage, 1.0f);
			int anim = FMath::RandRange(0, 1);
			if (anim == 0)
			{
				animInstance->Montage_JumpToSection(FName("Hit"), animationMontage);
			}
			else {
				animInstance->Montage_JumpToSection(FName("Hit2"), animationMontage);
			}
			
		}
	}
	return true;
}