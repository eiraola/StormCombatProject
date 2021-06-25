// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"
void AMainPlayerController::BeginPlay(){
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Using"));
	if (HUDOverlayAsset) {
		UE_LOG(LogTemp, Warning, TEXT("Using"));
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
		HUDOverlay->AddToViewport();
		HUDOverlay->SetVisibility(ESlateVisibility::Visible);
	}
}
