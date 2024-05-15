// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "SYAbilityDataAsset.generated.h"

class UGameplayAbility;
UCLASS()
class SY_API USYAbilityDataAsset : public UDataAsset
{
	GENERATED_BODY()



protected:
	//UPROPERTY(EditDefaultsOnly)
	//TMap<FGameplayTag, TSubclassOf<UGameplayAbility>> 
};
