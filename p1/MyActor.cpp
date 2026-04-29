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
	
	SetActorLocation(FVector(0, 0, 50));
	for (int32 i = 0; i < 10; ++i) {
		Move();
		TriggerEvent();
	}	
	for (int32 i = 0; i < 10; ++i) {
		Turn();
	}
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT(""));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, FString::Printf(TEXT("Total distance traveled : %f"), TotalDistance));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, FString::Printf(TEXT("Total number of events : %d"), numberevent));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("Data Report"));
}

void AMyActor::TriggerEvent()
{
	bool TriggerEvent = (FMath::RandRange(0, 1) == 1);

	if (TriggerEvent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("EVENT TRIGGERED!"));

		++numberevent;
	}
}

void AMyActor::Move()
{
	FVector Target;
	Target.X = FMath::FRandRange(-50.0, 50.0);
	Target.Y = FMath::FRandRange(-50.0, 50.0);
	Target.Z = 0;

	FVector OldLoc = GetActorLocation();

	AddActorWorldOffset(Target);

	FVector CurrentLocation = GetActorLocation();

	FVector NewLoc = GetActorLocation();

	TotalDistance += FVector::Dist(OldLoc, NewLoc);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *CurrentLocation.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Move #%d"), (++numbermove)));
		
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

	FRotator CurrentRotation = GetActorRotation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, *CurrentRotation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentRotation.ToString());
}
