// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFrameWork.h"
#include "BTTask_FindPatrolPoint.h"
#include "PatrolPoint.h"
#include "PatrolAI.h"
#include "BehaviorTree/BlackboardComponent.h"




EBTNodeResult::Type UBTTask_FindPatrolPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	APatrolAI* PatrolCon = Cast<APatrolAI>(OwnerComp.GetAIOwner());

	if (PatrolCon)
	{
		UBlackboardComponent* BlackboardComp = PatrolCon->GetBlackboardComp();

		APatrolPoint* CurrentPatrolPoint = Cast<APatrolPoint>(BlackboardComp->GetValueAsObject("NewWaypoint"));

		TArray<AActor*> PossiblePoints = PatrolCon->GetPatrolPoint();

		APatrolPoint* NextPoint = nullptr;

		if (PatrolCon->CurrentPoint != PossiblePoints.Num() - 1)
		{
			NextPoint = Cast<APatrolPoint>(PossiblePoints[++PatrolCon->CurrentPoint]);
		}
		else
		{
			NextPoint = Cast<APatrolPoint>(PossiblePoints[0]);
			PatrolCon->CurrentPoint = 0;
		}

		BlackboardComp->SetValueAsObject("NewWaypoint", NextPoint);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
