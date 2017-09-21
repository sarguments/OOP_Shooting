#include "stdafx.h"
#include "Base.h"
#include "Player.h"

CPlayer::CPlayer()
{
	// TODO : 플레이어 초기화

	_x = 10;
	_y = 10;
	_type = eObjType::Player;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Action()
{
	wprintf(L"플레이어 액션\n");
}

void CPlayer::Draw()
{
	wprintf(L"플레이어 드로우\n");
}