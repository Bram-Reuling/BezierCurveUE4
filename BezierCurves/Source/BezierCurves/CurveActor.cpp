// Fill out your copyright notice in the Description page of Project Settings.


#include "CurveActor.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACurveActor::ACurveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACurveActor::BeginPlay()
{
	Super::BeginPlay();
	
	float TValue = 0;

	while (TValue < 1.0f)
	{
		CurvePath.Add(CalculateCubicBezierCurvePath(TValue));
		TValue += TIncreaseValue;
	}

	DrawPath();
}

// Called every frame
void ACurveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ACurveActor::CalculateCubicBezierCurvePath(float T) const
{
	const FVector ActorLocation = GetActorLocation();
	return (FMath::Pow(1 - T, 3) * PointZero)
			+ (3 * FMath::Pow(1 - T, 2) * T * PointOne)
			+ (3 * (1 - T) * FMath::Square(T) * PointTwo)
			+ (FMath::Pow(T, 3) * PointThree) + ActorLocation; 
}

void ACurveActor::DrawPath()
{
	const int PointsInPath = CurvePath.Num() - 1;

	for (int IndexOne = 0; IndexOne < PointsInPath; ++IndexOne)
	{
		DrawDebugLine(GetWorld(), CurvePath[IndexOne], CurvePath[IndexOne + 1], FColor::Red, true, -1, 0, 5);
	}
}