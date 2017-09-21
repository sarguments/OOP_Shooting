#include "stdafx.h"
#include "Scene.h"
#include "TitleScene.h"

CTitleScene::CTitleScene(CSceneManager * pMgr)
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

CTitleScene::~CTitleScene()
{
}

void CTitleScene::Update()
{
	cs_MoveCursor(30, 10);
	wprintf(L"Title�� ������Ʈ\n");

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

void CTitleScene::Replace()
{
	wprintf(L"Title�� ���÷��̽�\n");

	_pMgr->SetNextScene(eSceneType::Game);
}
