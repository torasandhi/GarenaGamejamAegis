// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsSubsystem.h"

void USettingsSubsystem::SetGraphicMode(EGraphicsMode graphic)
{
	_graphicsMode = graphic;
}

EGraphicsMode USettingsSubsystem::GetGraphicsMode()
{
	return _graphicsMode;
}

void USettingsSubsystem::SetVolume(float volume)
{
	_currentVolume = volume;
}

float USettingsSubsystem::GetVolume()
{
	return _currentVolume;
}
