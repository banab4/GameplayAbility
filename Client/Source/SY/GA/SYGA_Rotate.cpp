// Fill out your copyright notice in the Description page of Project Settings.
#include "SYGA_Rotate.h"
#include "GameFramework/RotatingMovementComponent.h"

void USYGA_Rotate::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (ActorInfo && ActorInfo->AvatarActor.IsValid())
	{
		if (URotatingMovementComponent* RotatingMovementComponent = ActorInfo->AvatarActor->GetComponentByClass<URotatingMovementComponent>())
		{
			RotatingMovementComponent->Activate();
		}
	}
}

void USYGA_Rotate::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (ActorInfo && ActorInfo->AvatarActor.IsValid())
	{
		if (URotatingMovementComponent* RotatingMovementComponent = ActorInfo->AvatarActor->GetComponentByClass<URotatingMovementComponent>())
		{
			RotatingMovementComponent->Deactivate();
		}
	}
}
