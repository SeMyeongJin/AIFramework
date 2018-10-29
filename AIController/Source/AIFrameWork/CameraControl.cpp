// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFrameWork.h"
#include "CameraControl.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraControl::ACameraControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChanges = 10.0f;
	const float SmoothBlendTime = 0.75f;
	
	TimeToCameraChange -= DeltaTime;
	if (TimeToCameraChange <= 0.0f)
	{
		TimeToCameraChange += TimeBetweenCameraChanges;

		// 로컬 플레이어의 콘트롤을 처리하는 액터를 찾습니다.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			{
				// 1 번 카메라로 즉시 컷해 들어갑니다.
				OurPlayerController->SetViewTarget(CameraOne);
			}
			else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			{
				// 2 번 카메라로 부드럽게 전환합니다.
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
		}
	}
}

