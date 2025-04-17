// Copyright Epic Games, Inc. All Rights Reserved.

#include "gbsGameMode.h"
#include "gbsCharacter.h"
#include "UObject/ConstructorHelpers.h"


APlayerController* AgbsGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	auto pc = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
	if (pc != NULL) {
		// Parse the playername from options
		FString PlayerName;
		if (FParse::Value(*Options, TEXT("playername="), PlayerName))
		{
			// Remove the '?' if it exists in the name
			int32 QuestionIndex;
			if (PlayerName.FindChar('?', QuestionIndex))
			{
				PlayerName = PlayerName.Left(QuestionIndex);
			}
			UE_LOG(LogTemp, Log, TEXT("Setting player name to: %s"), *PlayerName);
			pc->SetName(PlayerName);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No playername found in options: %s"), *Options);
		}
	}
	return pc;
}

AgbsGameMode::AgbsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
