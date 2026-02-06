// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWorldSubsystem.h"

void UEnemyWorldSubsystem::RegisterEnemy(TScriptInterface<IInterfaceEnemy> enemy)
{
	enemys.Add(enemy);
}

TArray<TScriptInterface<IInterfaceEnemy>> UEnemyWorldSubsystem::GetAllEnemys()
{
	return enemys;
}
