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
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* ItemStaticMeshComponent;

	UPROPERTY()
	UNiagaraComponent* ItemNiagaraComponent;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* ItemNiagaraSystem;

	UPROPERTY(EditDefaultsOnly)
	UItemsPrimaryDataAsset* ItemData;

	UPROPERTY(EditDefaultsOnly)
	float BobSpeed = 40.0f;

	UPROPERTY(EditDefaultsOnly)
	float MaxBobDelta = 5.0f;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	USceneComponent* RootSceneComponent;

	UPROPERTY()
	FColor RarityColor;

	UPROPERTY()
	FVector StartingLocation;

	float TotalAliveTime;

	bool UpdateStaticMesh();

	void RandomizeStaticMeshLocation();

	void PerformStaticMeshBob();

	void AddLocationDeltaToStaticMesh(FVector& Delta);

	void StartNiagaraEffect();

	void StopNiagaraEffect();
};
