// Fill out your copyright notice in the Description page of Project Settings.


#include "CubicCurveActor.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACubicCurveActor::ACubicCurveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubicCurveActor::BeginPlay()
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
void ACubicCurveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ACubicCurveActor::CalculateCubicBezierCurvePath(float T) const
{
	const FVector ActorLocation = GetActorLocation();
	return (FMath::Pow(1 - T, 3) * PointZero)
			+ (3 * FMath::Pow(1 - T, 2) * T * PointOne)
			+ (3 * (1 - T) * FMath::Square(T) * PointTwo)
			+ (FMath::Pow(T, 3) * PointThree) + ActorLocation; 
}

void ACubicCurveActor::DrawPath()
{
	const int PointsInPath = CurvePath.Num() - 1;

	for (int IndexOne = 0; IndexOne < PointsInPath; ++IndexOne)
	{
		DrawDebugLine(GetWorld(), CurvePath[IndexOne], CurvePath[IndexOne + 1], FColor::Red, true, -1, 0, 5);
	}
}