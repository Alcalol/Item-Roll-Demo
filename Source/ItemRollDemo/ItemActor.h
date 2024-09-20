// Copyright Tony Sze 2024

#pragma once

#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

class UStaticMeshComponent;
class UStaticMesh;
class UItemsPrimaryDataAsset;
class UNiagaraSystem;

UCLASS()
class ITEMROLLDEMO_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AItemActor();

protected:
	UPROPERTY()
	UStaticMeshComponent* ItemStaticMeshComponent;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* ItemNiagaraEffect;

	UPROPERTY(EditDefaultsOnly)
	UItemsPrimaryDataAsset* ItemData;

	virtual void BeginPlay() override;
};
