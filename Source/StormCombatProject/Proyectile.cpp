// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectile.h"
#include "Combatant.h"
#include "Main.h"

#include "Enemy.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AProyectile::AProyectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	proyectile = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Proyectile"));
	//RootComponent = proyectile;
	
	collisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = collisionVolume;
	//collisionVolume->SetupAttachment(GetRootComponent());
	proyectile->SetupAttachment(GetRootComponent());
	velocity = 110;
	rotationSpeed = 500;
	damage = 20.f;
	

}

// Called when the game starts or when spawned
void AProyectile::BeginPlay()
{
	Super::BeginPlay();
	target = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	collisionVolume->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	collisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AProyectile::OnProyectileBeginOverlap);
	proyectile->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	proyectile->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	
}

// Called every frame
void AProyectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Advance(DeltaTime);
	RotateMesh(DeltaTime);
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
	FRotator targetRotationPoint = UKismetMathLibrary::RInterpTo(currentRotation, targetLookAt, DeltaTime, 4.5f);
	FRotator targetRotation;
	targetRotation.Pitch = currentRotation.Pitch;
	targetRotation.Yaw = targetRotationPoint.Yaw;
	targetRotation.Roll = currentRotation.Roll;
	SetActorRotation(targetRotation);


}
void AProyectile::OnProyectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if(OtherActor){
		bool bImpl = OtherActor->GetClass()->ImplementsInterface(UCombatant::StaticClass());
		
		ICombatant* pCastingValue = Cast<ICombatant>(OtherActor);
		if (pCastingValue) {
			
			pCastingValue->Execute_setDamage(OtherActor, damage);
			Destroy();
			//pCastingValue->setDamage_Implementation(20.0f);
			
			//ICombatant::Execute_setDamage(OtherActor,20.0f);
		
		}
	}

}

void AProyectile::SetTarget(class APawn* ptarget) {
	target = ptarget;

}

void AProyectile::RotateMesh(float DeltaTime) {
	FRotator targetRotation;
	FRotator currentRotation = proyectile->GetComponentRotation();
	targetRotation.Pitch = currentRotation.Pitch;
	targetRotation.Yaw = currentRotation.Yaw + rotationSpeed * DeltaTime;
	targetRotation.Roll = currentRotation.Roll;
	proyectile->SetWorldRotation(targetRotation);
}
