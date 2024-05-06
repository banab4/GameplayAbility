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

void ASYRotateActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (RotatingMovementComponent)
	{
		RotatingMovementComponent->bAutoActivate = false;
		RotatingMovementComponent->Deactivate();
	}

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

		for (UClass* AbilityClass : GrantedAbilityClasses)
		{
			FGameplayAbilitySpec Spec(AbilityClass);
			AbilitySystemComponent->GiveAbility(Spec);
		}
	}
	
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(RotateTimerHandle,this, &ThisClass::OnRotateTimer, 3, true);
	}
}

bool ASYRotateActor::IsRotating()
{
	if (AbilitySystemComponent)
	{
		FGameplayTag Tag = FGameplayTag::RequestGameplayTag(TEXT("Actor.State.Rotate"));
		if (AbilitySystemComponent->HasAnyMatchingGameplayTags(FGameplayTagContainer(Tag)))
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
		FGameplayTagContainer TagContainer(FGameplayTag::RequestGameplayTag(TEXT("Actor.Action.Rotate")));
		if (IsRotating())
		{
			AbilitySystemComponent->CancelAbilities(&TagContainer);
		}
		else
		{
			AbilitySystemComponent->TryActivateAbilitiesByTag(TagContainer);
		}
	}
}