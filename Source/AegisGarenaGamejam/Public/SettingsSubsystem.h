// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Graphics.h"
#include "SettingsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class AEGISGARENAGAMEJAM_API USettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	USettingsSubsystem() = default;
	~USettingsSubsystem() = default;
	
private:
	EGraphicsMode _graphicsMode;
	float _currentVolume = 50;
	
public:
	UFUNCTION(BlueprintCallable)
	void SetGraphicMode(EGraphicsMode graphic);
	
	UFUNCTION(BlueprintCallable)
	EGraphicsMode GetGraphicsMode();
	
	UFUNCTION(BlueprintCallable)
	void SetVolume(float volume);
	
	UFUNCTION(BlueprintCallable)
	float GetVolume();
	
};
