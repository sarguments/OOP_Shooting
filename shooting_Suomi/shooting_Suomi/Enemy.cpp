#include "stdafx.h"
#include "Base.h"
#include "Enemy.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "CLinkedList.h"

//CEnemy::CEnemy()
//{
//	_type = eObjType::Enemy;
//	_dir = eDir::Right;
//}

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
	// ���� ��ȯ
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

	// �̵� ó��
	if (_dir == eDir::Left)
	{
		_x--;
	}
	else
	{
		_x++;
	}
}

void CEnemy::Draw()
{
	SpriteDraw(_x, _y, 'E');
}