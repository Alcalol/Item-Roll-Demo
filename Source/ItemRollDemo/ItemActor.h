// Copyright Tony Sze 2024

#pragma once

#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

class UStaticMeshComponent;
class UStaticMesh;
class UItemsPrimaryDataAsset;
class UNiagaraSystem;
class UNiagaraComponent;

UCLASS()
class ITEMROLLDEMO_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AItemActor();

	bool ChangeItem(UItemsPrimaryDataAsset* ItemDataAsset);
	
	const UItemsPrimaryDataAsset* GetItemData();

protected:
	UPROPERTY()
	UStaticMeshComponent* ItemStaticMeshComponent;

	UPROPERTY()
	UNiagaraComponent* ItemNiagaraComponent;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* ItemNiagaraSystem;

	UPROPERTY(EditDefaultsOnly)
	UItemsPrimaryDataAsset* ItemData;

	virtual void BeginPlay() override;

	bool UpdateStaticMesh();

	FColor GetItemRarityColor();

	void StartNiagaraEffect();

	void StopNiagaraEffect();
};
