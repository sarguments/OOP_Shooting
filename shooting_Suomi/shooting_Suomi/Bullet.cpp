#include "stdafx.h"
#include "Base.h"
#include "Bullet.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "CLinkedList.h"

CBullet::CBullet(CGameScene * pScene)
{
	_pScene = pScene;

	_type = eObjType::Bullet;
}

CBullet::~CBullet()
{
}

void CBullet::Action()
{
	_y--;
}

void CBullet::Draw()
{
	SpriteDraw(_x, _y, 'i');
}