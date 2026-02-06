// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// Simple string print
#define SLOG(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, x);}

// Formatted print (like printf)
#define SLOGF(Format, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT(Format), ##__VA_ARGS__));}