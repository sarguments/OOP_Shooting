#include "stdafx.h"
#include "Scene.h"
#include "EndScene.h"

CEndScene::CEndScene(CSceneManager * pMgr)
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

CEndScene::~CEndScene()
{
}

void CEndScene::Update()
{
	///////////////////////////////////////////////
	BufferClear();
	char temp[] = "�λ�..";
	char temp2[] = "END.. 3���� �ٽ� �����մϴ�";
	memcpy(&g_backBuf[5][5], temp, sizeof(temp));
	memcpy(&g_backBuf[7][5], temp2, sizeof(temp2));
	BufferFlip();
	///////////////////////////////////////////////

	// end QueryPerformanceCounter ���Ѵ�.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	if ((double)diffTime / _oneSecondFreq > 3)
	{
		// beginTime �ٽ� ����
		QueryPerformanceCounter(&_beginTime);

		_pMgr->SetNextScene(eSceneType::Title);
	}
}