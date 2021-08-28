// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubicCurveActor.generated.h"

UCLASS()
class BEZIERCURVES_API ACubicCurveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubicCurveActor();

	UPROPERTY()
	TArray<FVector> CurvePath;

	UFUNCTION()
	FVector CalculateCubicBezierCurvePath(float T) const;

	UFUNCTION()
	void DrawPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Control Points", Meta = (MakeEditWidget = true))
	FVector PointZero;

	UPROPERTY(EditAnywhere, Category = "Control Points", Meta = (MakeEditWidget = true))
	FVector PointOne;

	UPROPERTY(EditAnywhere, Category = "Control Points", Meta = (MakeEditWidget = true))
	FVector PointTwo;

	UPROPERTY(EditAnywhere, Category = "Control Points", Meta = (MakeEditWidget = true))
	FVector PointThree;

	UPROPERTY(EditAnywhere, Category = "Value Settings")
	float TIncreaseValue = 0.125f;

};
