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

	ItemStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Static Mesh"));

	ItemStaticMeshComponent->SetupAttachment(RootComponent);
}

bool AItemActor::ChangeItem(UItemsPrimaryDataAsset* ItemDataAsset)
{
	StopNiagaraEffect();

	ItemData = ItemDataAsset;

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

FColor AItemActor::GetItemRarityColor()
{
	UItemGameInstance* GameInstance = Cast<UItemGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	UItemRarityDataAsset* RarityDataAsset = GameInstance->RarityDataAsset;

	if (RarityDataAsset)
	{
		return RarityDataAsset->GetRarityColor(ItemData->GetItemRarity());
	}

	return FColor();

}

void AItemActor::StartNiagaraEffect()
{
	if (ItemData)
	{
		ItemNiagaraComponent->SetNiagaraVariableLinearColor(FString("EffectColor"), GetItemRarityColor());
	}

	ItemNiagaraComponent->Activate();
}

void AItemActor::StopNiagaraEffect()
{
	ItemNiagaraComponent->Deactivate();
}

