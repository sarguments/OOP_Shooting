#include "stdafx.h"
#include "Base.h"
#include "Player.h"

#include "Scene.h"
#include "GameScene.h"

CPlayer::CPlayer(CGameScene* pScene)
{
	_pGameScene = pScene;

	// 플레이어 초기화
	_x = dfSCREEN_WIDTH / 2;
	_y = dfSCREEN_HEIGHT - 5;
	_type = eObjType::Player;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Action()
{
	KeyProcess();
}

void CPlayer::Draw()
{
	SpriteDraw(_x, _y, 'U');
}

void CPlayer::Move(eDir param)
{
	switch (param)
	{
	case eDir::Left:
	{
		_x--;
	}
	break;
	case eDir::Right:
	{
		_x++;
	}
	break;
	}
}

void CPlayer::KeyProcess()
{
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) // RR
	{
		if (!CheckPos(_x + 1, _y))
		{
			return;
		}

		Move(eDir::Right);
	}

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) // LL
	{
		if (!CheckPos(_x - 1, _y))
		{
			return;
		}

		Move(eDir::Left);
	}

	if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		Shot();
	}
}

void CPlayer::Shot()
{
	_pGameScene->CreateBullet(eObjType::Player, _x, _y - 1);
}