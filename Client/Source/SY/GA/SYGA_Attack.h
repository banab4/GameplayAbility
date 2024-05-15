// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SYGA_Attack.generated.h"

class UAnimMontage;
UCLASS()
class SY_API USYGA_Attack : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	

protected:
	UFUNCTION()
	void OnTaskCompleted();
	

protected:
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* Montage;
};
