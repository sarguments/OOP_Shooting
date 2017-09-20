#include "stdafx.h"
#include "Scene.h"
#include "TitleScene.h"

CTitleScene::CTitleScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;
}

CTitleScene::~CTitleScene()
{
}

void CTitleScene::Update()
{
	wprintf(L"Title�� ������Ʈ\n");

	static int titleTest = 0;
	titleTest++;

	if (titleTest == 10)
	{
		Replace();
		titleTest = 0;
	}
}

void CTitleScene::Replace()
{
	wprintf(L"Title�� ���÷��̽�\n");

	_pMgr->SetNextScene(eSceneType::Game);
}
