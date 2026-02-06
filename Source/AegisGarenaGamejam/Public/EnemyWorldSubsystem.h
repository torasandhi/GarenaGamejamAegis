// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Interfaces/InterfaceEnemy.h"
#include "EnemyWorldSubsystem.generated.h"

UCLASS()
class AEGISGARENAGAMEJAM_API UEnemyWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UEnemyWorldSubsystem() = default;
	~UEnemyWorldSubsystem() = default;
	
public:
	UFUNCTION(BlueprintCallable, Category = "Enemy")
	void RegisterEnemy(TScriptInterface<IInterfaceEnemy> enemy);
	
	UFUNCTION(BlueprintCallable, Category = "Enemy")
	TArray<TScriptInterface<IInterfaceEnemy>> GetAllEnemys();
	
private:
	TArray<TScriptInterface<IInterfaceEnemy>> enemys;
};
