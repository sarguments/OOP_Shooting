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
	BufferClear();

	// 1�ʴ� Ÿ�̸� ���ļ��� ��´�, min, max
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_oneSecondFreq = (double)freq.QuadPart;

	// begin QueryPerformanceCounter ���ؼ� �ִ´�.
	QueryPerformanceCounter(&_beginTime);

	CBase* newObject = new CPlayer(this);
	_gameList.push_back(newObject);

	// TODO : �׽�Ʈ
	CBase* newObject2 = new CPlayer(this);
	_gameList.push_back(newObject2);

	CBase* newObject3 = new CPlayer(this);
	_gameList.push_back(newObject3);
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
	//wprintf(L"����Ʈ ���� �ߴٳ�!\n");
}

void CGameScene::Update()
{
	// TODO : �׽�Ʈ

	// end QueryPerformanceCounter ���Ѵ�.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	CLinkedList<CBase*>::Iterator nowIter = _gameList.begin();
	CLinkedList<CBase*>::Iterator endIter = _gameList.end();

	while (nowIter != endIter)
	{
		CPlayer* pPlayer = (CPlayer*)(*nowIter);
		pPlayer->Action();
		pPlayer->Draw();

		nowIter++;
	}

	if ((double)diffTime / _oneSecondFreq > 3)
	{
		//wprintf(L"\n3�� ����!!\n");

		// beginTime �ٽ� ����
		QueryPerformanceCounter(&_beginTime);

		Replace();
	}
}

void CGameScene::Replace()
{
	//wprintf(L"Game�� ���÷��̽�\n");

	_pMgr->SetNextScene(eSceneType::End);
}

CLinkedList<CBase*>* CGameScene::GetListPtr()
{
	return &_gameList;
}