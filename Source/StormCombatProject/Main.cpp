// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include "Proyectile.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraComponent.h"
#include "Particles/ParticleSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Particles/ParticleSystemComponent.h"
#include "TimerManager.h"
#include "Animation/AnimMontage.h"

// Sets default values
AMain::AMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	specialParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpecialParticles"));
	specialParticles->SetupAttachment(GetRootComponent());
	specialParticles->SetVisibility(false);
	ultimateParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("UltimateParticles"));
	ultimateParticles->SetupAttachment(GetRootComponent());
	ultimateParticles->SetVisibility(false);
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm

	maxChackra = 100;
	maxHealth = 100;
	health = maxHealth;
	chackra = maxChackra/2;
	bIsChargingChackra = false;
	bIsSpecialCharged = false;
	bIsUltimateCharged = false;
	dechargeTime = 1.0f;
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
	comboNumber = 0;
	canHit = true;

}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();
	SetGameEnemy();
}

void AMain::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Chackra", IE_Pressed, this, &AMain::ChargeChackra);
	PlayerInputComponent->BindAction("Chackra", IE_Released, this, &AMain::StopChargeChackra);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMain::Attack);
	PlayerInputComponent->BindAction("Shuriken", IE_Pressed, this, &AMain::LaunchShuriken);
	//PlayerInputComponent->BindAction("Shuriken", IE_Released, this, &AMain::StopChargeChackra);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMain::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMain::LookUpAtRate);
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LookToEnemy(DeltaTime);
	
	if(GetWorld()->GetFirstPlayerController()->GetInputKeyTimeDown(FKey("E"))>0.5f){
		HandleChackra(DeltaTime);
	}
}


void AMain::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}
void AMain::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMain::MoveForward(float Value)
{
	if (playerStatus != EPlayerStatus::EMS_Movement) return;
	if (bIsChargingChackra) return;
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMain::MoveRight(float Value)
{
	if (playerStatus != EPlayerStatus::EMS_Movement) return;
	if (bIsChargingChackra) return;
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
void AMain::SetGameEnemy(){
	TSubclassOf<AEnemy> ObjectiveClass;
	ObjectiveClass = AEnemy::StaticClass();
	TArray<AActor*> TargetActor;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ObjectiveClass, FName(TEXT("Enemy")), TargetActor);
	UE_LOG(LogTemp, Warning, TEXT("Looking for enemies"));
	for (AActor* Actor : TargetActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("There is an enemy"));
		LockOnObjective = Cast<AEnemy>(Actor);
	}

}
void AMain::LookToEnemy(float deltaTime){
	if (LockOnObjective) {

		FVector initRotation = FollowCamera->GetComponentLocation();
		FVector endRotation = LockOnObjective->GetActorLocation();
		FRotator targetLookAt = UKismetMathLibrary::FindLookAtRotation(initRotation, endRotation);
		FRotator currentRotation = GetController()->GetControlRotation();
		FRotator targetRotationPoint = UKismetMathLibrary::RInterpTo(currentRotation, targetLookAt, deltaTime, 5.0f);
		FRotator targetRotation;
		targetRotation.Pitch = currentRotation.Pitch;
		targetRotation.Yaw = targetRotationPoint.Yaw;
		targetRotation.Roll = currentRotation.Roll;


		GetController()->SetControlRotation(targetRotation);
	}
}

void AMain::ChargeChackra(){
	
	
}
void AMain::StopChargeChackra() {
	if (!bIsChargingChackra) {
		ChargeSpecial();
		return;
	}
	bIsChargingChackra = false;
	if (Auxiliar_Effect) {
		Auxiliar_Effect->DestroyComponent();
	}
}
void AMain::HandleChackra(float deltaTime) {
	if (NS_Chacra && !bIsChargingChackra ) {
		Auxiliar_Effect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NS_Chacra, GetActorLocation(), FRotator(0, 0, 0), FVector(0.5, 0.5, 0.5), false, true, ENCPoolMethod::FreeInPool, true);
		bIsChargingChackra = true;
	}
	chackra = (chackra>= maxChackra)?maxChackra: chackra += 5 * deltaTime;
	
}
void AMain::ChargeSpecial(){

	if (bIsSpecialCharged) {
		ChargeUltimate();
		return;
	}
	GetWorldTimerManager().SetTimer(DechargeTimer, this, &AMain::Decharge, dechargeTime);
	specialParticles->SetVisibility(true);
	bIsSpecialCharged = true;
}
void AMain::ChargeUltimate() {
	if (!bIsUltimateCharged) {
		bIsUltimateCharged = true;
		GetWorldTimerManager().ClearTimer(DechargeTimer);
		GetWorldTimerManager().SetTimer(DechargeTimer, this, &AMain::Decharge, dechargeTime);
		specialParticles->SetVisibility(false);
		ultimateParticles->SetVisibility(true);
	}
}

void AMain::Decharge() {
	bIsSpecialCharged = false;
	bIsUltimateCharged = false;
	specialParticles->SetVisibility(false);
	ultimateParticles->SetVisibility(false);
}

bool AMain::setDamage_Implementation(float damage) {
	health = health - damage;
	return true;
}
void AMain::LaunchShuriken() {
	if (playerStatus != EPlayerStatus::EMS_Movement) return;
	SetPlayerStatus(EPlayerStatus::EMS_Shoot);
	LookAtEnemy();
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (animInstance) {
		if(animationMontage){
			animInstance->Montage_Play(animationMontage, 1.0f);
			animInstance->Montage_JumpToSection(FName("Shoot"), animationMontage);
		}
	}
	UWorld* world = GetWorld();
	FActorSpawnParameters SpawnParams;
	FVector forward = GetShootSpawnPos();
	if(ShurikenToSpawn){
		if (world) {
			AProyectile* proyectile = world->SpawnActor<AProyectile>(ShurikenToSpawn, forward, FRotator(0.f), SpawnParams);
			if (proyectile) {
				proyectile->SetTarget(LockOnObjective);
			}
		}
	}
	
}
void AMain::ShootEnd() {
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
	comboNumber = 0;
	canHit = true;
}
FRotator  AMain::GetLookAtRotationYaw(FVector target) {
	FRotator LookAtRotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), target);
	FRotator LookAtRotationYaw(0.f, LookAtRotator.Yaw, 0.f);
	return LookAtRotationYaw;

}
void AMain::Attack() {
	if ((playerStatus != EPlayerStatus::EMS_Movement && comboNumber == 0)) {
		UE_LOG(LogTemp, Warning, TEXT("NOPE"));
		return;
		
	}
	if (!canHit) return;
	canHit = false;
	SetPlayerStatus(EPlayerStatus::EMS_Attack);
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	LookAtEnemy();
	if (animInstance) {
		
		if (animationMontage) {
			switch (comboNumber)
			{
			case 0:
				animInstance->Montage_Play(animationMontage, 1.0f);
				animInstance->Montage_JumpToSection(FName("Punch"), animationMontage);
				comboNumber++;
				break;
			case 1:
				animInstance->Montage_Play(animationMontage, 1.0f);
				animInstance->Montage_JumpToSection(FName("Punch2"), animationMontage);
				comboNumber++;
				break;
			case 2:
				animInstance->Montage_Play(animationMontage, 1.0f);
				animInstance->Montage_JumpToSection(FName("Kick2"), animationMontage);
				comboNumber++;
				break;
			case 3:
				animInstance->Montage_Play(animationMontage, 1.0f);
				animInstance->Montage_JumpToSection(FName("PunchCombo"), animationMontage);
				comboNumber++;
				break;
			case 4:
				animInstance->Montage_Play(animationMontage, 1.0f);
				animInstance->Montage_JumpToSection(FName("Kick"), animationMontage);
				comboNumber++;
				break;
			default:
				break;
			}
			
		}
	}

}

void AMain::LookAtEnemy() {
	FRotator LookAtYaw = GetLookAtRotationYaw(LockOnObjective->GetActorLocation());
	SetActorRotation(LookAtYaw);
}

FVector AMain::GetShootSpawnPos(){
	FVector forward = GetActorForwardVector();
	forward.Normalize();
	forward = forward * 300;
	forward = forward + GetActorLocation();
	return forward;
}

void AMain::CanCombo() {
	
	canHit = true;
}