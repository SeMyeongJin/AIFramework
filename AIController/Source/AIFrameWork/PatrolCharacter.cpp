// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFrameWork.h"
#include "PatrolCharacter.h"
#include "PatrolAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
APatrolCharacter::APatrolCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
}

// Called when the game starts or when spawned
void APatrolCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &APatrolCharacter::OnTargetCaught);
	}
}

// Called every frame
//void APatrolCharacter::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

// Called to bind functionality to input
void APatrolCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APatrolCharacter::OnTargetCaught(APawn * Pawn)
{
	APatrolAI* PatrolController = Cast<APatrolAI>(GetController());

	if (PatrolController)
	{
		PatrolController->TargetCaught(Pawn);
	}
}

