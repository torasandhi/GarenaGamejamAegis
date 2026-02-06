// Fill out your copyright notice in the Description page of Project Settings.

#include "AegisGarenaGamejam/Public/WaypointsSubsystem.h"
#include "Engine/World.h"
#include "AegisGarenaGamejam/Public/WaypointActor.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "Logging/LogMacros.h"

void UWaypointsSubsystem::RegisterWaypoint(AWaypointActor* Waypoint)
{
	// Simplified registration logic
	if (Waypoint)
	{
		Waypoints.AddUnique(Waypoint);
	}
}

void UWaypointsSubsystem::UnregisterWaypoint(AWaypointActor* Waypoint)
{
	if (Waypoint)
	{
		Waypoints.Remove(Waypoint);
	}
}

TArray<AWaypointActor*> UWaypointsSubsystem::GetWaypoints() const
{
	// Convert TObjectPtr array to raw pointer array for Blueprint consumption
	TArray<AWaypointActor*> OutWaypoints;
	for (const auto& Pt : Waypoints)
	{
		if (Pt) OutWaypoints.Add(Pt);
	}
	return OutWaypoints;
}