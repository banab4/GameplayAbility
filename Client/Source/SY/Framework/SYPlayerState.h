// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SYPlayerState.generated.h"


class UAbilitySystemComponent;

UCLASS()
class SY_API ASYPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASYPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

protected:
	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent; 
};
