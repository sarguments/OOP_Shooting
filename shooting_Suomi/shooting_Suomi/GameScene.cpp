#include "stdafx.h"

#include "Base.h"
#include "Scene.h"
#include "GameScene.h"

#include "CLinkedList.h"

CGameScene::CGameScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;
}

CGameScene::~CGameScene()
{
}

void CGameScene::Update()
{
	wprintf(L"Game의 업데이트\n");

	static int gameTest = 0;
	gameTest++;

	if (gameTest == 10)
	{
		Replace();
		gameTest = 0;
	}
}

void CGameScene::Replace()
{
	wprintf(L"Game의 리플레이스\n");

	_pMgr->SetNextScene(eSceneType::End);
}
