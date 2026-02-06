// cpp
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "WaypointsSubsystem.generated.h"

class AWaypointActor;

UCLASS()
class AEGISGARENAGAMEJAM_API UWaypointsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	// Single array to hold all waypoints
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AWaypointActor>> Waypoints;

public:
	UFUNCTION(BlueprintCallable, Category = "Waypoints")
	void RegisterWaypoint(AWaypointActor* Waypoint);

	UFUNCTION(BlueprintCallable, Category = "Waypoints")
	void UnregisterWaypoint(AWaypointActor* Waypoint);

	// Returns the array so you can get specific actors/positions later
	UFUNCTION(BlueprintPure, Category = "Waypoints")
	TArray<AWaypointActor*> GetWaypoints() const;
};