#include "stdafx.h"

#include "Base.h"
#include "Scene.h"
#include "GameScene.h"

#include "CLinkedList.h"

CGameScene::CGameScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;

	// 1초당 타이머 주파수를 얻는다, min, max
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_oneSecondFreq = (double)freq.QuadPart;

	// begin QueryPerformanceCounter 구해서 넣는다.
	QueryPerformanceCounter(&_beginTime);

	cs_ClearScreen();
}

CGameScene::~CGameScene()
{
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
