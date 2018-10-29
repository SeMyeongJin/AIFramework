// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "PatrolAI.generated.h"

/**
 * 
 */
UCLASS()
class AIFRAMEWORK_API APatrolAI : public AAIController
{
	GENERATED_BODY()


	/* behavior tree component */
	class UBehaviorTreeComponent* BehaviorComp;
	
	/* blackboard component */
	class UBlackboardComponent* BlackboardComp;

	/* blackboard key value */
	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName NewWaypointKey;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName TargetKey;

	TArray<AActor*> PatrolPoint;

	virtual void Possess(APawn* Pawn) override;

public:
	APatrolAI();

	int32 CurrentPoint = 0;

	void TargetCaught(APawn* Pawn);

	UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	TArray<AActor*> GetPatrolPoint() const { return PatrolPoint; }
};
