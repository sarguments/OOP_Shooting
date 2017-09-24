#include "stdafx.h"
#include "Scene.h"
#include "EndScene.h"

CEndScene::CEndScene(CSceneManager * pMgr)
{
	_pMgr = pMgr;

	// 화면 지우기
	BufferClear();

	// 1초당 타이머 주파수를 얻는다, min, max
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_oneSecondFreq = (double)freq.QuadPart;

	// begin QueryPerformanceCounter 구해서 넣는다.
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
	char temp[] = "인생..";
	char temp2[] = "END.. 3초후 다시 시작합니다";
	memcpy(&g_backBuf[5][5], temp, sizeof(temp));
	memcpy(&g_backBuf[7][5], temp2, sizeof(temp2));
	BufferFlip();
	///////////////////////////////////////////////

	// end QueryPerformanceCounter 구한다.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	if ((double)diffTime / _oneSecondFreq > 3)
	{
		// beginTime 다시 구함
		QueryPerformanceCounter(&_beginTime);

		_pMgr->SetNextScene(eSceneType::Title);
	}
}