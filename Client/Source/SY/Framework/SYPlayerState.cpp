// Fill out your copyright notice in the Description page of Project Settings.
#include "SYPlayerState.h"
#include "AbilitySystemComponent.h"

ASYPlayerState::ASYPlayerState()
	:Super()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(FName("ASC"));
}

UAbilitySystemComponent* ASYPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
