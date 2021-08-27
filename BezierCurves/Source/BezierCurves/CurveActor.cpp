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
	
}

// Called every frame
void ACurveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACurveActor::CalculatePath()
{
}

void ACurveActor::DrawPath()
{
}