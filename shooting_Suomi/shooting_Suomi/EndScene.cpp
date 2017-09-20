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
	wprintf(L"End�� ������Ʈ\n");

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
	wprintf(L"End�� ���÷��̽�\n");

	_pMgr->SetNextScene(eSceneType::Title);
}
