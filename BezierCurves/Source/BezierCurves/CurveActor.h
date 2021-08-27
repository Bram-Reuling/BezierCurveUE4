// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CurveActor.generated.h"

UCLASS()
class BEZIERCURVES_API ACurveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACurveActor();

	UPROPERTY()
	TArray<FVector> CurvePath;

	UFUNCTION()
	FVector CalculateBezierCurvePath(float T) const;

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

};
