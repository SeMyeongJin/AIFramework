// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class AIFRAMEWORK_API UBTTask_FindPatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()



	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
