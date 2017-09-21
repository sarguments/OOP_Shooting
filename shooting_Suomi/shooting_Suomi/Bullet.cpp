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
}

CBullet::~CBullet()
{
}

void CBullet::Action()
{
}

void CBullet::Draw()
{
}