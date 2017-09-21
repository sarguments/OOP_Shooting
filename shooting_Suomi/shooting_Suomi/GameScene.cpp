#include "stdafx.h"

#include "Base.h"
#include "Scene.h"
#include "GameScene.h"

#include "CLinkedList.h"

CGameScene::CGameScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;

	// 1�ʴ� Ÿ�̸� ���ļ��� ��´�, min, max
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_oneSecondFreq = (double)freq.QuadPart;

	// begin QueryPerformanceCounter ���ؼ� �ִ´�.
	QueryPerformanceCounter(&_beginTime);

	cs_ClearScreen();
}

CGameScene::~CGameScene()
{
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
