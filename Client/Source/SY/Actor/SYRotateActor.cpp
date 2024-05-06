// Fill out your copyright notice in the Description page of Project Settings.


#include "SYRotateActor.h"
#include "AbilitySystemComponent.h"
#include "GA/SYGA_Rotate.h"
#include "GameFramework/RotatingMovementComponent.h"

ASYRotateActor::ASYRotateActor()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(FName("ASC"));
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(FName("M"));
}

void ASYRotateActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASYRotateActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	FGameplayAbilitySpec Spec(USYGA_Rotate::StaticClass());
	AbilitySystemComponent->GiveAbility(Spec);
	
	RotatingMovementComponent->Deactivate();


	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(RotateTimerHandle,this, &ThisClass::OnRotateTimer, 3, true);
	}
}

bool ASYRotateActor::IsRotating()
{
	if (FGameplayAbilitySpec* Spec = AbilitySystemComponent ? AbilitySystemComponent->FindAbilitySpecFromClass(USYGA_Rotate::StaticClass()) : nullptr)
	{
		if (Spec->IsActive())
		{
			return true;
		}
	}

	return false;
}

void ASYRotateActor::OnRotateTimer()
{
	if (AbilitySystemComponent)
	{
		if (IsRotating())
		{
			AbilitySystemComponent->CancelAbility(USYGA_Rotate::StaticClass()->GetDefaultObject<UGameplayAbility>());
		}
		else
		{
			AbilitySystemComponent->TryActivateAbilityByClass(USYGA_Rotate::StaticClass());
		}
	}
}