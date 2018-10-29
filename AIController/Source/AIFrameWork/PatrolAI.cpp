// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFrameWork.h"
#include "PatrolAI.h"
#include "PatrolCharacter.h"
#include "PatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"




APatrolAI::APatrolAI()
{
	/* Initailize Comp and blackboard key value */
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	NewWaypointKey = "NewWaypoint";
	TargetKey = "Target";

	CurrentPoint = 0;
}

void APatrolAI::TargetCaught(APawn * Pawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetKey, Pawn);
	}
}



void APatrolAI::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);

	APatrolCharacter* MyCharacter = Cast<APatrolCharacter>(Pawn);

	if (MyCharacter)
	{
		if (MyCharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(MyCharacter->BehaviorTree->BlackboardAsset));
		}

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPoint::StaticClass(), PatrolPoint);

		BehaviorComp->StartTree(*MyCharacter->BehaviorTree);
	}
}


