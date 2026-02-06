#include "BTTask_GetNextWaypoint.h"
#include "WaypointsSubsystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "WaypointActor.h"
#include "AegisGarenaGamejam/AegisGarenaGamejam.h"

UBTTask_GetNextWaypoint::UBTTask_GetNextWaypoint()
{
	NodeName = "Get Next Waypoint";

	// Filter the keys to only show relevant types in the editor
	TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_GetNextWaypoint, TargetActorKey),
	                               AActor::StaticClass());
	WaypointIndexKey.AddIntFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_GetNextWaypoint, WaypointIndexKey));
}

EBTNodeResult::Type UBTTask_GetNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Blackboard) return EBTNodeResult::Failed;

	//  Get Subsystem
	UWorld* World = OwnerComp.GetWorld();
	UWaypointsSubsystem* WaypointSys = World ? World->GetSubsystem<UWaypointsSubsystem>() : nullptr;

	if (!WaypointSys) return EBTNodeResult::Failed;

	//  Get Waypoints list
	TArray<AWaypointActor*> Waypoints = WaypointSys->GetWaypoints();
	
	if (Waypoints.Num() == 0) return EBTNodeResult::Failed;

	//  Get current index
	int32 CurrentIndex = Blackboard->GetValueAsInt(WaypointIndexKey.SelectedKeyName);

	// Safety check: if index is out of bounds, reset to 0
	if (!Waypoints.IsValidIndex(CurrentIndex))
	{
		CurrentIndex = 0;
	}

	//  Update Target Actor Key
	Blackboard->SetValueAsObject(TargetActorKey.SelectedKeyName, Waypoints[CurrentIndex]);
		SLOGF("SelectedKeyName : %s", *Waypoints[CurrentIndex]->GetFName().ToString());

	//  Calculate and Save Next Index (Looping)
	int32 NextIndex = (CurrentIndex + 1) % Waypoints.Num();
	Blackboard->SetValueAsInt(WaypointIndexKey.SelectedKeyName, NextIndex);
	

	return EBTNodeResult::Succeeded;
}
