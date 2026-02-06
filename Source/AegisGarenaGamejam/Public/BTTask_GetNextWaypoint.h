#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_GetNextWaypoint.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class AEGISGARENAGAMEJAM_API UBTTask_GetNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_GetNextWaypoint();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	// Select the Blackboard Key that stores the Target Actor (Object)
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetActorKey;

	// Select the Blackboard Key that stores the Current Index (Integer)
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WaypointIndexKey;
};