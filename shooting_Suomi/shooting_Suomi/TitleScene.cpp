#include "stdafx.h"
#include "Scene.h"
#include "TitleScene.h"

#include "SceneManager.h"

CTitleScene::CTitleScene(CSceneManager * pMgr)
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

CTitleScene::~CTitleScene()
{
	CLinkedList<stMatrix*>::Iterator nowIter = _titleList.begin();
	CLinkedList<stMatrix*>::Iterator endIter = _titleList.end();

	while (nowIter != endIter)
	{
		stMatrix* pDelete = (*nowIter);
		nowIter++;
		delete pDelete;
	}

	_titleList.Clear();
}

void CTitleScene::Update()
{
	BufferClear();

	const int SCREEN_WIDTH = 81;
	const int SCREEN_HEIGHT = 24;

	if (rand() % 100 > 70)
	{
		stMatrix* tempObj = new stMatrix;
		tempObj->_ch = rand() % ('Z' - 'A') + 'A';
		tempObj->_distance = rand() % SCREEN_HEIGHT;
		tempObj->_nFrame = (rand() % 5) + 1;
		tempObj->_nStay = tempObj->_nFrame;
		tempObj->_x = rand() % (SCREEN_WIDTH - 2);
		tempObj->_y = 0;

		_titleList.push_back(tempObj);
	}

	CLinkedList<stMatrix*>::Iterator nowIter = _titleList.begin();
	CLinkedList<stMatrix*>::Iterator endIter = _titleList.end();

	while (nowIter != endIter)
	{
		stMatrix* pObj = *(nowIter);

		--pObj->_nStay;

		if (pObj->_nStay == 0)
		{
			++pObj->_y;
			pObj->_nStay = pObj->_nFrame;
		}

		if (pObj->_distance == pObj->_y || pObj->_y > (SCREEN_HEIGHT - 1))
		{
			nowIter = _titleList.erase(nowIter);
			delete pObj;
			continue;
		}

		SpriteDraw(pObj->_x, pObj->_y, pObj->_ch);

		nowIter++;
	}

	///////////////////////////////////////////////
	char textBuf[] = "NOW LOADING...";
	memcpy(&g_backBuf[SCREEN_HEIGHT - 1][5], textBuf, sizeof(textBuf));
	BufferFlip();
	///////////////////////////////////////////////

	// end QueryPerformanceCounter 구한다.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);

	// end - begin
	__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

	if ((double)diffTime / _oneSecondFreq > 5)
	{
		// beginTime 다시 구함
		QueryPerformanceCounter(&_beginTime);

		_pMgr->SetNextScene(eSceneType::Game);
	}
}