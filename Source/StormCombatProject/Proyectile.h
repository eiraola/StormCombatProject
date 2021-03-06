// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectile.generated.h"

UCLASS()
class STORMCOMBATPROJECT_API AProyectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectile();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	class UStaticMeshComponent* proyectile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	class USphereComponent* collisionVolume;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	AActor* target;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float rotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float damage;
	UFUNCTION()
	void OnProyectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void SetTarget(APawn* ptarget);
	void SetRotationSpeed(float ratio);
	void SetVelocity(float speed);
	void SetDamage(float dam);

private:
	void Advance(float DeltaTime);
	void RotateToTarget(float DeltaTime);
	void RotateMesh(float DeltaTime);
	

};
