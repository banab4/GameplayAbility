// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SYRotateActor.generated.h"

class UGameplayAbility;
class URotatingMovementComponent;
class UAbilitySystemComponent;

UCLASS()
class SY_API ASYRotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASYRotateActor();

protected:
	virtual void PostInitializeComponents() override;

	bool IsRotating();
	void OnRotateTimer();

protected:
	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY()
	URotatingMovementComponent* RotatingMovementComponent;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilityClasses;

	FTimerHandle RotateTimerHandle;
};
