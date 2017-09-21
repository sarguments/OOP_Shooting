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
}

CEnemy::~CEnemy()
{
}

void CEnemy::Action()
{
}

void CEnemy::Draw()
{
}