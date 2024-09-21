// Copyright Tony Sze 2024

#pragma once

#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

class USceneComponent;
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

	bool ChangeItem(UItemsPrimaryDataAsset* ItemDataAsset, FColor ItemRarityColor);
	
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

private:
	UPROPERTY()
	USceneComponent* RootSceneComponent;

	UPROPERTY()
	FColor RarityColor;

	bool UpdateStaticMesh();

	void StartNiagaraEffect();

	void StopNiagaraEffect();
};
