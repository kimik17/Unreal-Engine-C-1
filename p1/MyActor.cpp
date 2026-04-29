// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(0, 0, 50);
	for (int32 i = 0; i < 10; ++i)
		Move();
	for (int32 i = 0; i < 10; ++i)
		Turn();
	
}

void AMyActor::Move()
{
	FVector Target;
	Target.X = FMath::FRandRange(-50.0, 50.0);
	Target.Y = FMath::FRandRange(-50.0, 50.0);
	Target.Z = 0;

	AddActorWorldOffset(Target);

	FVector CurrentLocation = GetActorLocation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *CurrentLocation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentLocation.ToString());
}

void AMyActor::Turn()
{
	FRotator DeltaRotation;
	DeltaRotation.Yaw = FMath::FRandRange(-180.0, 180.0);
	DeltaRotation.Pitch = 0;
	DeltaRotation.Roll = 0;

	AddActorWorldRotation(DeltaRotation);

	FVector CurrentLocation = GetActorLocation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *CurrentLocation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentLocation.ToString());
}
