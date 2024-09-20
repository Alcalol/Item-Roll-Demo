// Copyright Tony Sze 2024


#include "ItemActor.h"
#include "Components/StaticMeshComponent.h"
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

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();

	if (ItemData)
	{
		ItemStaticMeshComponent->SetStaticMesh(ItemData->GetItemStaticMesh());
	}
}

