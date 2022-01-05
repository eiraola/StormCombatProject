// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuCharacter.h"
#include "Marker.h"
// Sets default values
AMenuCharacter::AMenuCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (menuStrings.Num()>0)
	{
		currentString = menuStrings[0];
		currentStringIndex = 0;
	}
	if (markers.Num() > 0)
	{
		currentMarker = markers[0];
		currentMarkerIndex = 0;
	}
}

// Called when the game starts or when spawned
void AMenuCharacter::BeginPlay()
{
	Super::BeginPlay();
	initialPosition = GetActorLocation();
	SetActorLocation(currentMarker + initialPosition, false);
	
}

// Called every frame
void AMenuCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMenuCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("MoveForward", this, &AMenuCharacter::NextMenuStat);
	PlayerInputComponent->BindAction("MenuUp", IE_Pressed, this, &AMenuCharacter::NextMenuStat);
	PlayerInputComponent->BindAction("MenuDown", IE_Pressed, this, &AMenuCharacter::PreviousMenuStat);
	

}

void AMenuCharacter::NextMenuStat()
{
	
	if (menuStrings.Num() > (currentStringIndex + 1))
	{
		currentStringIndex = currentStringIndex +1;
		
	}
	else {
		currentStringIndex = 0;
	}
	if (markers.Num() > (currentMarkerIndex + 1))
	{
		currentMarkerIndex = currentMarkerIndex + 1;

	}
	else {
		currentMarkerIndex = 0;
	}

	currentMarker = markers[currentMarkerIndex];
	SetActorLocation(currentMarker + initialPosition, false);
	currentString = menuStrings[currentStringIndex];
}
void AMenuCharacter::PreviousMenuStat() {

	if (0 <= (currentStringIndex - 1))
	{
		currentStringIndex = currentStringIndex - 1;

	}
	else {
		currentStringIndex = menuStrings.Num()-1;
	}

	if (0 <= (currentMarkerIndex - 1))
	{
		currentMarkerIndex = currentMarkerIndex - 1;

	}
	else {
		currentMarkerIndex = markers.Num() - 1;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Text, %d"), currentStringIndex);

	currentMarker = markers[currentMarkerIndex];
	SetActorLocation(currentMarker + initialPosition, false);
	currentString = menuStrings[currentStringIndex];
}
