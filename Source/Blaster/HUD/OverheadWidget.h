// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* DisplayText;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* PlayerNameText;
	void SetPlayerNameText(FString TextToDisplay);

	void SetDisplayText(FString TextToDisplay);

	UFUNCTION(BlueprintCallable)
		void ShowPlayerNetRole(APawn* InPawn);

	UFUNCTION(BlueprintCallable)
		void ShowPlayerDisplayName(APawn* InPawn);

protected:
	//virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	virtual void NativeDestruct() override;

	UPROPERTY(EditAnywhere, Category = "Overhead Widget Properties", meta = (AllowPrivateAccess = true, Units = "Seconds"))
		float GetPlayerNameTimeout = 30.f;
	UPROPERTY(EditAnywhere, Category = "Overhead Widget Properties", meta = (AllowPrivateAccess = true, Units = "Seconds"))
		float GetPlayerNameInterval = 0.1f;
	float TotalTime = -0.1f;

};