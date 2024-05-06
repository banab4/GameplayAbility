// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SYRotateActor.generated.h"

class URotatingMovementComponent;
class UAbilitySystemComponent;

UCLASS()
class SY_API ASYRotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASYRotateActor();

	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	bool IsRotating();
	void OnRotateTimer();

protected:
	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	URotatingMovementComponent* RotatingMovementComponent;

	FTimerHandle RotateTimerHandle;
};
