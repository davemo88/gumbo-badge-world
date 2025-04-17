// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "gbsGameMode.generated.h"

UCLASS(minimalapi)
class AgbsGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual APlayerController* Login
	(
		UPlayer* NewPlayer,
		ENetRole InRemoteRole,
		const FString& Portal,
		const FString& Options,
		const FUniqueNetIdRepl& UniqueId,
		FString& ErrorMessage
	) override;

public:
	AgbsGameMode();
};



