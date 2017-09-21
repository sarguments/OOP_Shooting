#include "stdafx.h"
#include "Scene.h"
#include "TitleScene.h"

CTitleScene::CTitleScene(CSceneManager * pMgr)
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

	cs_ClearScreen();
}

CTitleScene::~CTitleScene()
{
}

void CTitleScene::Update()
{
	///////////////////////////////////////////////
	BufferClear();
	char temp[] = "NOW LOADING...";
	memcpy(&g_backBuf[5][5], temp, sizeof(temp));
	BufferFlip();
	///////////////////////////////////////////////

	//cs_MoveCursor(30, 10);
	//wprintf(L"Title�� ������Ʈ\n");

	// TODO : �׽�Ʈ

	// end QueryPerformanceCounter ���Ѵ�.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	if ((double)diffTime / _oneSecondFreq > 3)
	{
		//wprintf(L"3�� ����!!\n");

		// beginTime �ٽ� ����
		QueryPerformanceCounter(&_beginTime);

		Replace();

		//iCnt = 0;
	}
}

void CTitleScene::Replace()
{
	//wprintf(L"Title�� ���÷��̽�\n");

	_pMgr->SetNextScene(eSceneType::Game);
}