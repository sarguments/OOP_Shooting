#include "stdafx.h"
#include "Scene.h"
#include "EndScene.h"

CEndScene::CEndScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;
}

CEndScene::~CEndScene()
{
}

void CEndScene::Update()
{
	wprintf(L"End의 업데이트\n");

	static int endTest = 0;
	endTest++;

	if (endTest == 10)
	{
		Replace();
		endTest = 0;
	}
}

void CEndScene::Replace()
{
	wprintf(L"End의 리플레이스\n");

	_pMgr->SetNextScene(eSceneType::Title);
}
