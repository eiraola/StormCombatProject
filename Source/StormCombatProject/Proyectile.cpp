// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	proyectile = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Proyectile"));
	proyectile->SetupAttachment(GetRootComponent());
	collisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	collisionVolume->SetupAttachment(GetRootComponent());
	velocity = 20;
	

}

// Called when the game starts or when spawned
void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	target = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
}

// Called every frame
void AProyectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Advance(DeltaTime);
	if(target){
		RotateToTarget(DeltaTime);
	}
	

}
void AProyectile::Advance(float DeltaTime){
	FVector currentPos = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	forwardVector.Normalize();
	currentPos = currentPos + (forwardVector * velocity * DeltaTime);
	SetActorLocation(currentPos);
}
void AProyectile::RotateToTarget(float DeltaTime){
	FVector initRotation = GetActorLocation();
	FVector endRotation = target->GetActorLocation();
	FRotator targetLookAt = UKismetMathLibrary::FindLookAtRotation(initRotation, endRotation);
	FRotator currentRotation = GetActorRotation();
	FRotator targetRotationPoint = UKismetMathLibrary::RInterpTo(currentRotation, targetLookAt, DeltaTime, 0.5f);
	FRotator targetRotation;
	targetRotation.Pitch = currentRotation.Pitch;
	targetRotation.Yaw = targetRotationPoint.Yaw;
	targetRotation.Roll = currentRotation.Roll;
	SetActorRotation(targetRotation);


}

