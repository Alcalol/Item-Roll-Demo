// Copyright Tony Sze 2024

#pragma once

#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

/**
 * Class responsible for the actual item existing in the world for players to pick up or interact with.
 */

class USceneComponent;
class UStaticMeshComponent;
class UStaticMesh;
class UItemsPrimaryDataAsset;
class UNiagaraSystem;
class UNiagaraComponent;
class USceneComponent;

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

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* NiagaraLocatorComponent;

	// The Niagara System effect to display at the NiagaraLocatorComponent position.
	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* ItemNiagaraSystem;

	// The item data asset specifying what item this is supposed to be.  Can be set at runtime via ChangeItem().
	UPROPERTY(EditDefaultsOnly)
	UItemsPrimaryDataAsset* ItemData;

	// The speed at which the object will bob up and down after spawning.
	UPROPERTY(EditDefaultsOnly)
	float BobSpeed = 40.0f;

	// The maximum delta from it's original position the item can bob.
	UPROPERTY(EditDefaultsOnly)
	float MaxBobDelta = 5.0f;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	USceneComponent* RootSceneComponent;

	UPROPERTY()
	UNiagaraComponent* ItemNiagaraComponent;

	UPROPERTY()
	FColor RarityColor;

	UPROPERTY()
	FVector StartingLocation;

	// Tracks how long the actor has been alive for.  Used for calculating item bob position.
	float TotalAliveTime;

	bool UpdateStaticMesh();

	void PerformStaticMeshBob();

	void AddLocationDeltaToStaticMesh(FVector& Delta);

	void StartNiagaraEffect();

	void StopNiagaraEffect();
};
