// Copyright Tony Sze 2024


#include "ItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "ItemTypes.h"
#include "ItemRarityDataAsset.h"
#include "ItemGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMesh.h"
#include "ItemsPrimaryDataAsset.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	ItemStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Static Mesh"));

	RootComponent = RootSceneComponent;
	ItemStaticMeshComponent->SetupAttachment(RootComponent);
}

bool AItemActor::ChangeItem(UItemsPrimaryDataAsset* ItemDataAsset, FColor ItemRarityColor)
{
	StopNiagaraEffect();

	ItemData = ItemDataAsset;
	RarityColor = ItemRarityColor;

	StartNiagaraEffect();

	return UpdateStaticMesh();
}

const UItemsPrimaryDataAsset* AItemActor::GetItemData()
{
	return ItemData;
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();

	RarityColor = FColor();

	if (ItemNiagaraSystem)
	{
		ItemNiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(ItemNiagaraSystem, ItemStaticMeshComponent, NAME_None, FVector(0.0f), FRotator(0.0f), EAttachLocation::SnapToTargetIncludingScale, true, false);
	}

	StartNiagaraEffect();

	UpdateStaticMesh();
}

bool AItemActor::UpdateStaticMesh()
{
	if (ItemData && ItemStaticMeshComponent)
	{
		ItemStaticMeshComponent->SetStaticMesh(ItemData->GetItemStaticMesh());

		return true;
	}

	return false;
}

void AItemActor::StartNiagaraEffect()
{
	if (ItemData)
	{
		ItemNiagaraComponent->SetNiagaraVariableLinearColor(FString("EffectColor"), RarityColor);

		ItemNiagaraComponent->Activate();
	}
}

void AItemActor::StopNiagaraEffect()
{
	ItemNiagaraComponent->Deactivate();
}

