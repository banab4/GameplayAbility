// Fill out your copyright notice in the Description page of Project Settings.


#include "SYGA_Attack.h"

#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "GameFramework/CharacterMovementComponent.h"

void USYGA_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UAbilityTask_PlayMontageAndWait* Task = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, TEXT("AttackTask"), Montage))
	{
		Task->OnCompleted.AddDynamic(this, &ThisClass::OnTaskCompleted);
		Task->OnInterrupted.AddDynamic(this, &ThisClass::OnTaskCompleted);
		Task->ReadyForActivation();

		if (ActorInfo)
		{
			if (UCharacterMovementComponent* Component = Cast<UCharacterMovementComponent>(ActorInfo->MovementComponent))
			{
				Component->SetMovementMode(MOVE_None);
			}
		}
	}
}

void USYGA_Attack::OnTaskCompleted()
{
	if (FGameplayAbilitySpec* Spec = GetCurrentAbilitySpec())
	{
		EndAbility(Spec->Handle, GetCurrentActorInfo(), GetCurrentActivationInfo(), true, true);

		if (UCharacterMovementComponent* Component = Cast<UCharacterMovementComponent>(GetCurrentActorInfo()->MovementComponent))
		{
			Component->SetMovementMode(MOVE_Walking);
		}
	}
}
