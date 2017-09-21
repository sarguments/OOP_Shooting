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

	// 화면 지우기
	cs_ClearScreen();

	// 1초당 타이머 주파수를 얻는다, min, max
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_oneSecondFreq = (double)freq.QuadPart;

	// begin QueryPerformanceCounter 구해서 넣는다.
	QueryPerformanceCounter(&_beginTime);

	CBase* newObject = new CPlayer;
	_gameList.push_back(newObject);
	wprintf(L"리스트에 넣다냥!\n");
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
	wprintf(L"리스트 정리 했다냥!\n");
}

void CGameScene::Update()
{
	cs_MoveCursor(30, 10);
	wprintf(L"Game의 업데이트\n");

	// TODO : 테스트

	// end QueryPerformanceCounter 구한다.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	if ((double)diffTime / _oneSecondFreq > 3)
	{
		wprintf(L"3초 지남!!\n");

		// beginTime 다시 구함
		QueryPerformanceCounter(&_beginTime);

		Replace();
	}
}

void CGameScene::Replace()
{
	wprintf(L"Game의 리플레이스\n");

	_pMgr->SetNextScene(eSceneType::End);
}
