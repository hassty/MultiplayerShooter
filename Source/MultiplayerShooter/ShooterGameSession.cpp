// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGameSession.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"

void AShooterGameSession::RegisterServer()
{
	UE_LOG(LogTemp, Log, TEXT("Registering server and creating session -------"));
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("No online subsystem found!!! -------"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Got online subsystem -------"));
	IOnlineSessionPtr Session = OnlineSubsystem->GetSessionInterface();
	UE_LOG(LogTemp, Log, TEXT("Got session interface -------"));
	FOnlineSessionSettings Settings;

	Settings.bIsDedicated = true;
	Settings.bIsLANMatch = false;
	Settings.bAllowJoinInProgress = true;
	Settings.bShouldAdvertise = true;
	Settings.NumPublicConnections = 32;
	Settings.bUsesPresence = true;

	UE_LOG(LogTemp, Log, TEXT("Initialized settings -------"));

	Session->CreateSession(0, GameSessionName, Settings);

	UE_LOG(LogTemp, Log, TEXT("Session created -------"));
}


