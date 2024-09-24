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
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	ItemStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Static Mesh"));
	NiagaraLocatorComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Niagara System Locator"));

	RootComponent = RootSceneComponent;
	ItemStaticMeshComponent->SetupAttachment(RootComponent);
	NiagaraLocatorComponent->SetupAttachment(RootComponent);
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

void AItemActor::BeginPlay()
{
	Super::BeginPlay();

	RarityColor = FColor();

	StartingLocation = ItemStaticMeshComponent->GetRelativeLocation();

	if (ItemNiagaraSystem)
	{
		ItemNiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(ItemNiagaraSystem, RootComponent, NAME_None, NiagaraLocatorComponent->GetRelativeLocation(), NiagaraLocatorComponent->GetRelativeRotation(), EAttachLocation::SnapToTargetIncludingScale, true, false);
	}

	StartNiagaraEffect();

	UpdateStaticMesh();
}

void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TotalAliveTime += DeltaTime;

	PerformStaticMeshBob();
}

bool AItemActor::UpdateStaticMesh()
{
	if (ItemData && ItemStaticMeshComponent)
	{
		if (UStaticMesh* MeshToUse = ItemData->GetItemStaticMesh())
		{
			ItemStaticMeshComponent->SetStaticMesh(MeshToUse);
		}
		if (UMaterialInterface* MaterialToUse = ItemData->GetItemMeshMaterial())
		{
			ItemStaticMeshComponent->SetMaterial(0, MaterialToUse);
		}

		return true;
	}

	return false;
}

void AItemActor::PerformStaticMeshBob()
{
	float BobDelta = TotalAliveTime * BobSpeed;

	BobDelta = FMath::Sin(TotalAliveTime) * MaxBobDelta;

	FVector NewDelta = FVector(0.0f, 0.0f, BobDelta);

	AddLocationDeltaToStaticMesh(NewDelta);
}

void AItemActor::AddLocationDeltaToStaticMesh(FVector& Delta)
{
	FVector FinalLocation = StartingLocation;

	FinalLocation += Delta;

	ItemStaticMeshComponent->SetRelativeLocation(FinalLocation);
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

