#include "stdafx.h"
#include "Base.h"
#include "Enemy.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "CLinkedList.h"

CEnemy::CEnemy(CGameScene* pScene)
{
	_pScene = pScene;

	_type = eObjType::Enemy;
	_dir = eDir::Right;
}

CEnemy::~CEnemy()
{
}

void CEnemy::Action()
{
	// 방향 전환
	if (abs(_bornX - _x) > 4)
	{
		if (_dir == eDir::Left)
		{
			_dir = eDir::Right;
		}
		else
		{
			_dir = eDir::Left;
		}
	}

	// 이동 처리
	if (_dir == eDir::Left)
	{
		_x--;
	}
	else
	{
		_x++;
	}

	int randNum = rand() % 100;
	if (randNum > 95)
	{
		Shot();
	}
}

void CEnemy::Draw()
{
	SpriteDraw(_x, _y, 'E');
}

void CEnemy::Shot()
{
	_pScene->CreateBullet(eObjType::Enemy, _x, _y + 1);
}