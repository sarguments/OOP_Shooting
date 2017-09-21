#include "stdafx.h"

#include "Base.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include "Scene.h"
#include "GameScene.h"

#include "CLinkedList.h"

CGameScene::CGameScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;

	// ȭ�� �����
	cs_ClearScreen();

	// 1�ʴ� Ÿ�̸� ���ļ��� ��´�, min, max
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_oneSecondFreq = (double)freq.QuadPart;

	// begin QueryPerformanceCounter ���ؼ� �ִ´�.
	QueryPerformanceCounter(&_beginTime);

	CBase* newObject = new CPlayer;
	_gameList.push_back(newObject);
	wprintf(L"����Ʈ�� �ִٳ�!\n");
}

CGameScene::~CGameScene()
{
	CLinkedList<CBase*>::Iterator nowIter = _gameList.begin();
	CLinkedList<CBase*>::Iterator endIter = _gameList.end();

	while (nowIter != endIter)
	{
		CBase* pDelete = (*nowIter);
		nowIter++;
		delete pDelete;
	}

	_gameList.Clear();
	wprintf(L"����Ʈ ���� �ߴٳ�!\n");
}

void CGameScene::Update()
{
	cs_MoveCursor(30, 10);
	wprintf(L"Game�� ������Ʈ\n");

	// TODO : �׽�Ʈ

	// end QueryPerformanceCounter ���Ѵ�.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	if ((double)diffTime / _oneSecondFreq > 3)
	{
		wprintf(L"3�� ����!!\n");

		// beginTime �ٽ� ����
		QueryPerformanceCounter(&_beginTime);

		Replace();
	}
}

void CGameScene::Replace()
{
	wprintf(L"Game�� ���÷��̽�\n");

	_pMgr->SetNextScene(eSceneType::End);
}
