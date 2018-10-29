// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PatrolCharacter.generated.h"

UCLASS()
class AIFRAMEWORK_API APatrolCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APatrolCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = AI)
	class UBehaviorTree* BehaviorTree;
	
	UPROPERTY(VisibleAnywhere, Category = AI)
	class UPawnSensingComponent* PawnSensingComp;

private:

	UFUNCTION()
		void OnTargetCaught(APawn* Pawn);
};
