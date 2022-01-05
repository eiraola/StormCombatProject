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
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Kismet/KismetMathLibrary.h"
#include "SkillBall.h"

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
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->SocketOffset = FVector(-130.0f, 100.0f, 100.0f);
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm
	CameraBoom->bDoCollisionTest = false;

	SkillCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SkillCameraBoom"));
	SkillCameraBoom->SetupAttachment(GetMesh());
	SkillCameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	SkillCameraBoom->SocketOffset = FVector(700.0f, 0.0f, 0.0f);
	SkillCameraBoom->bUsePawnControlRotation = false; // Rotate the arm based on the controller
	SkillCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SkillCamera"));
	SkillCamera->SetupAttachment(SkillCameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	SkillCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm
	SkillCameraBoom->bDoCollisionTest = false;
	
	//RigthArmComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Rhand"));
	//RigthArmComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("RHandS"));
	//RigthArmComponent->SetWorldScale3D(FVector(0.2, 0.4, 0.2));
	RLeftArmComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RLHand"));
	RLeftArmComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("RHandS"));
	RLeftArmComponent->SetWorldScale3D(FVector(0.2, 0.4, 0.2));
	LeftArmComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("LHand"));
	LeftArmComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("LHandS"));
	LeftArmComponent->SetWorldScale3D(FVector(0.2, 0.4, 0.2));

	RigthLegComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RLeg"));
	RigthLegComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("RLegS"));
	RigthLegComponent->SetWorldScale3D(FVector(0.2, 0.2, 0.4));
	LeftLegComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("LLeg"));
	LeftLegComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("LLegS"));
	RigthLegComponent->SetWorldScale3D(FVector(0.2, 0.2, 0.4));


	maxChackra = 100;
	maxHealth = 100;
	health = maxHealth;
	chackra = maxChackra / 2;
	bIsChargingChackra = false;
	bIsChargingBreak = false;
	bIsSpecialCharged = false;
	bIsUltimateCharged = false;
	dechargeTime = 1.0f;
	SetHitElement(EHitElement::EMS_None);
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
	comboNumber = 0;
	canHit = true;
	canDamage = true;
	RHandActive = false;
	LHandActive = false;
	RLegActive = false;
	LLegActive = false;
	isDashing = false;
	forwardInputValue = 0.0;
	rightInputValue = 0.0;
	dodgeAgain = false;
	numAttacksBuffer = 0;
	chargingChackraStart = 0.0f;
	chargingBreakStart = 0.0f;
	currentChackraChargingTime = 0.0f;
	bIsChackraButtonPressed = false;
	bIsTransformed = false;
	skillBoomRotation = -30.f;
	bIsTransforming = false;
	
	
}
// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();
	SetGameEnemy();
	//RigthArmComponent->OnComponentBeginOverlap.AddDynamic(this, &AMain::HitEnemy);
	RLeftArmComponent->OnComponentBeginOverlap.AddDynamic(this, &AMain::RPunchOnBeginOverlap);
	LeftArmComponent->OnComponentBeginOverlap.AddDynamic(this, &AMain::LPunchOnBeginOverlap);

	RigthLegComponent->OnComponentBeginOverlap.AddDynamic(this, &AMain::RKickBeginOverlap);
	LeftLegComponent->OnComponentBeginOverlap.AddDynamic(this, &AMain::LKickBeginOverlap);
}

void AMain::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMain::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Chackra", IE_Pressed, this, &AMain::ChargeChackra);
	PlayerInputComponent->BindAction("Chackra", IE_Released, this, &AMain::StopChargeChackra);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMain::Attack);
	PlayerInputComponent->BindAction("Shuriken", IE_Pressed, this, &AMain::LaunchShuriken);
	//PlayerInputComponent->BindAction("Shuriken", IE_Released, this, &AMain::StopChargeChackra);
	PlayerInputComponent->BindAction("Dodge", IE_Pressed, this, &AMain::Dodge);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMain::TurnAtRate);
	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &AMain::LookUpAtRate);
	


}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SkillCameraMovement(DeltaTime);
	LookToOwner();
	LookToEnemy(DeltaTime);
	SkillCameraMovement(DeltaTime);
	HandleChackra(DeltaTime);	
	if (isDashing) {
		DashToEnemy(DeltaTime);
	}
	
}


void AMain::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	//AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}
void AMain::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	//AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMain::MoveForward(float Value)
{
	forwardInputValue = Value;
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
	rightInputValue = Value;
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
	if (GetCharacterMovement()->IsFalling()) return;
	bIsChackraButtonPressed = true;
	chargingChackraStart = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	currentChackraChargingTime = chargingChackraStart;
}
void AMain::StopChargeChackra() {
	bIsChackraButtonPressed = false;
	chargingChackraStart = 0.0f;
	if (!bIsChargingChackra) {
		ChargeSpecial();
		return;
	}
	bIsChargingChackra = false;
	bIsChargingBreak = false;
	if (Auxiliar_Effect) {
		Auxiliar_Effect->DestroyComponent();
	}
	if (Break_Effect) {
		Break_Effect->DestroyComponent();
	}
}
void AMain::HandleChackra(float deltaTime) {

	if (!bIsChackraButtonPressed) return;

	if (UGameplayStatics::GetRealTimeSeconds(GetWorld()) - chargingChackraStart > 0.5f) {
		if (NS_Chacra && !bIsChargingChackra) {
			Auxiliar_Effect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NS_Chacra, GetActorLocation() - FVector(0, 1, 0), FRotator(0, 0, 0), FVector(0.5, 0.5, 0.5), false, true, ENCPoolMethod::AutoRelease, true);
			bIsChargingChackra = true;
		}
		chackra = (chackra >= maxChackra) ? maxChackra : chackra += 5 * deltaTime;
		ChargeBreak();
	}
}
void AMain::UseUltimate()
{
}

void AMain::UseSpecialAttack()
{
	SetPlayerStatus(EPlayerStatus::EMS_Skill);
	LookAtEnemy();
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (animInstance) {
		if (animationMontage) {
			animInstance->Montage_Play(animationMontage, 1.0f);
			animInstance->Montage_JumpToSection(FName("SkillBall"), animationMontage);
		}
	}
}

void AMain::EndSkillLaunch()
{
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
}

void AMain::ChargeBreak(){
	if (chackra != maxChackra || bIsTransformed) return;
	if (bIsChargingBreak) {
		if ((UGameplayStatics::GetRealTimeSeconds(GetWorld()) - chargingBreakStart > 0.5f))
		{
			bIsTransformed = true;
			TransformToSpecial();
		}
	}
	if (NS_Break && !bIsChargingBreak)
	{
		chargingBreakStart = UGameplayStatics::GetRealTimeSeconds(GetWorld());
		
		bIsChargingBreak = true;
		Break_Effect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NS_Break, GetActorLocation() - FVector(0, 1, 0), FRotator(0, 0, 0), FVector(0.5, 0.5, 0.5), false, true, ENCPoolMethod::AutoRelease, true);
		if (Auxiliar_Effect) {
			Auxiliar_Effect->DestroyComponent();
		}
		
	}
		
	
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
	if (GetCharacterMovement()->IsFalling()) return;
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
	
	
}
void AMain::SpawnShuriken() {
	UWorld* world = GetWorld();
	FActorSpawnParameters SpawnParams;
	FVector forward = GetShootSpawnPos();
	if (ShurikenToSpawn) {
		if (world) {
			AProyectile* proyectile = world->SpawnActor<AProyectile>(ShurikenToSpawn, forward, FRotator(0.f), SpawnParams);
			if (proyectile) {
				proyectile->SetTarget(LockOnObjective);
			}
		}
	}
}
void AMain::SpawnFireball()
{
	UWorld* world = GetWorld();
	FActorSpawnParameters SpawnParams;
	FVector forward = GetShootSpawnPos();
	if (SkillToSpawn) {
		if (world) {
			AProyectile* proyectile = world->SpawnActor<AProyectile>(SkillToSpawn, forward, FRotator(0.f), SpawnParams);
			if (proyectile) {
				proyectile->SetTarget(LockOnObjective);
				proyectile->SetRotationSpeed(0.0f);
				proyectile->SetVelocity(500.0f);
			}
		}
	}
}
void AMain::ShootEnd() {
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
	
}
FRotator  AMain::GetLookAtRotationYaw(FVector target) {
	FRotator LookAtRotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), target);
	FRotator LookAtRotationYaw(0.f, LookAtRotator.Yaw, 0.f);
	return LookAtRotationYaw;

}
void AMain::Attack() {
	if (GetCharacterMovement()->IsFalling()) return;
	if (playerStatus == EPlayerStatus::EMS_Attack) {

		numAttacksBuffer++;
		return;
	}
	if ((playerStatus != EPlayerStatus::EMS_Movement && comboNumber == 0)) {
		
		return;
		
	}
	if (bIsSpecialCharged)
	{
		UseSpecialAttack();
		return;
	}
	if (bIsUltimateCharged)
	{
		return;
	}
	SelectAttack();

}

void AMain::SelectAttack()
{
	//if (!canHit) return;
	canHit = false;
	SetPlayerStatus(EPlayerStatus::EMS_Attack);
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	LookAtEnemy();
	if (animInstance) {
		if (FooshSound)
		{
			UGameplayStatics::PlaySound2D(this, FooshSound);
		}
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
				animInstance->Montage_JumpToSection(FName("Punch3"), animationMontage);
				comboNumber++;
				break;
			case 3:
				animInstance->Montage_Play(animationMontage, 1.0f);
				animInstance->Montage_JumpToSection(FName("Punch4"), animationMontage);
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

void AMain::LookToOwner()
{
	FVector initRotation = FollowCamera->GetComponentLocation();
	FVector endRotation = GetMesh()->GetComponentLocation();
	FRotator targetLookAt = UKismetMathLibrary::FindLookAtRotation(initRotation, endRotation);
	CameraBoom->SetWorldRotation(targetLookAt);
}

void AMain::TransformToSpecial()
{
	InitSkillCameraMovement();
	FollowCamera->Deactivate();
	SkillCamera->Activate();
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (dashAnimationMontage)
	{
		//StopChargeChackra();
		
		if (Auxiliar_Effect) {
			Auxiliar_Effect->DestroyComponent();
		}
		if (Break_Effect) {
			Break_Effect->DestroyComponent();
		}
		if(BreakMaterial)
			GetMesh()->SetMaterial(0, BreakMaterial);
		GetWorldTimerManager().SetTimer(BreakTimer, this, &AMain::BackToNormalTransformation, 30.0f);
		animInstance->Montage_Play(dashAnimationMontage, 1.0f);
		animInstance->Montage_JumpToSection(FName("Transformation"), dashAnimationMontage);
	}
	
}

void AMain::BackToNormalTransformation()
{
	if (InitialMaterial)
		GetMesh()->SetMaterial(0, InitialMaterial);
	bIsTransformed = false;
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
void AMain::HitEnemy(AActor* OtherActor, UPrimitiveComponent* OtherComp){
	if (OtherActor) {
		AEnemy* enemy = Cast<AEnemy>(OtherActor);
		if (enemy != LockOnObjective) return;
		bool bImpl = OtherActor->GetClass()->ImplementsInterface(UCombatant::StaticClass());
		
		ICombatant* pCastingValue = Cast<ICombatant>(OtherActor);
		if (PunchSound)
		{
			UGameplayStatics::PlaySound2D(this, PunchSound);
		}
		
		if (pCastingValue) {

			pCastingValue->Execute_setDamage(OtherActor, 30.0);
		}
	}

}
void AMain::SetHitElement(EHitElement element) {
	hitElement = element;

}
void AMain::BackToMainCamera()
{
	SkillCamera->Deactivate();
	FollowCamera->Activate();
	bIsTransforming = false;
}
void AMain::RPunchOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (hitElement != EHitElement::EMS_RHand) return;
	HitEnemy(OtherActor,  OtherComp);
}

void AMain::LPunchOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (hitElement != EHitElement::EMS_LHand) return;
	HitEnemy(OtherActor, OtherComp);
}

void AMain::RKickBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (hitElement != EHitElement::EMS_LLeg) return;
	HitEnemy(OtherActor, OtherComp);
}

void AMain::LKickBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (hitElement != EHitElement::EMS_RLeg) return;
	HitEnemy(OtherActor, OtherComp);
}
void AMain::DashToEnemy(float DeltaTime) {

	FVector initRotation = GetActorLocation();
	FVector endRotation = LockOnObjective->GetActorLocation();
	FRotator targetLookAt = UKismetMathLibrary::FindLookAtRotation(initRotation, endRotation);
	FRotator currentRotation = GetActorRotation();
	FRotator targetRotationPoint = UKismetMathLibrary::RInterpTo(currentRotation, targetLookAt, DeltaTime, 4.5f);
	FRotator targetRotation;
	targetRotation.Pitch = currentRotation.Pitch;
	targetRotation.Yaw = targetRotationPoint.Yaw;
	targetRotation.Roll = currentRotation.Roll;
	SetActorRotation(targetRotation);
	FRotator LookAtYaw = GetLookAtRotationYaw(LockOnObjective->GetActorLocation());
	SetActorRotation(LookAtYaw);

	const FRotator YawRotation(0, LookAtYaw.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction*800, 70000.0,true);

}
void AMain::InitSkillCameraMovement()
{
	
	FRotator r = SkillCameraBoom->GetRelativeRotation();
	r.Pitch = (-30.0f);
	FHitResult* OutSweepHitResult = nullptr;
	SkillCameraBoom->SetRelativeLocationAndRotation(SkillCameraBoom->GetRelativeLocation(), r, true, OutSweepHitResult, ETeleportType::TeleportPhysics);
	bIsTransforming = true;
}
void AMain::SkillCameraMovement(float deltaTime)
{
	if (!bIsTransforming) return;
	
	FRotator r = SkillCameraBoom->GetRelativeRotation();
	r.Pitch += 20 * deltaTime;
	
	if (r.Pitch >20)
	{
		r.Pitch =(20.0f);
	}
	FHitResult* OutSweepHitResult = nullptr;
	SkillCameraBoom->SetRelativeLocationAndRotation(SkillCameraBoom->GetRelativeLocation(), r, true, OutSweepHitResult, ETeleportType::TeleportPhysics);
	
	
}
void AMain::MakeStepSound()
{
	if (StepSound)
	{
		UGameplayStatics::PlaySound2D(this, StepSound);
	}
	
}
void AMain::Jump() {
	if (GetCharacterMovement()->IsFalling()) return;
	if (playerStatus!= EPlayerStatus::EMS_Movement) return;
	if ((bIsSpecialCharged || bIsUltimateCharged)){
		BeginDash();
			
	}
	else {
		Super::Jump();
	}
}
void AMain::BeginDash() {
	SetPlayerStatus(EPlayerStatus::EMS_Dash);

	//	//UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetCharacterMovement()->MaxWalkSpeed);
	//
	//
	//	GetCharacterMovement()->MaxWalkSpeed = 9000;
	//	GetWorldTimerManager().SetTimer(ChargeTimer, this, &AMain::StopCharge, 3.0f);
	//	isDashing = true;
	LookAtEnemy();
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (animationMontage)
	{
		//StopChargeChackra();


		//GetWorldTimerManager().SetTimer(BreakTimer, this, &AMain::BackToNormalTransformation, 30.0f);

		animInstance->Montage_Play(animationMontage, 1.0f);
		animInstance->Montage_JumpToSection(FName("attck"), animationMontage);
	}
}
void AMain::StopDash() {
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
}
void AMain::StopCharge() {
	isDashing = false;
	GetCharacterMovement()->MaxWalkSpeed = 800;
}

void AMain::Dodge() {
	if (GetCharacterMovement()->IsFalling()) return;
	if (playerStatus == EPlayerStatus::EMS_Dodge) {
		dodgeAgain = true;
		return;
	}
	numAttacksBuffer = 0;
	AttackEnd();
	DodgeAction();
	
}

void AMain::DodgeAction()
{
	
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (dashAnimationMontage)
	{
		playerStatus = EPlayerStatus::EMS_Dodge;
		FVector initRotation = GetActorLocation();
		FVector endRotation = LockOnObjective->GetActorLocation();
		FRotator targetLookAt = UKismetMathLibrary::FindLookAtRotation(initRotation, endRotation);
		FRotator targetRotation;
		targetRotation.Pitch = targetLookAt.Pitch;
		targetRotation.Yaw = targetLookAt.Yaw;
		targetRotation.Roll = targetLookAt.Roll;
		SetActorRotation(targetRotation);
		FString anim = "DodgeB";
		if (UKismetMathLibrary::Abs(forwardInputValue) < UKismetMathLibrary::Abs(rightInputValue)) {
			anim = (rightInputValue > 0) ? "DodgeR" : "DodgeL";
		}
		animInstance->Montage_Play(dashAnimationMontage, 1.0f);
		animInstance->Montage_JumpToSection(FName(anim), dashAnimationMontage);
	}
}

void AMain::DodgeEnd()
{
	if (dodgeAgain)
	{
		dodgeAgain = false;
		DodgeAction();
	}
	playerStatus = EPlayerStatus::EMS_Movement;
}

void AMain::AttackEnd()
{
	if (numAttacksBuffer > 0 && comboNumber <=3)
	{
		numAttacksBuffer--;
		SelectAttack();
		return;
	}
	SetPlayerStatus(EPlayerStatus::EMS_Movement);
	comboNumber = 0;
	numAttacksBuffer = 0;
	canHit = true;
}
