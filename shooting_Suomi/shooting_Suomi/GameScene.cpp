#include "stdafx.h"
#include "Scene.h"
#include "GameScene.h"

#include "Base.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include "SceneManager.h"
#include "CLinkedList.h"

void CGameScene::GameProc(CBase * param)
{
	switch (param->GetType())
	{
	case eObjType::Bullet:
	{
		CBullet* actionObj = (CBullet*)param;
		actionObj->Action();
		actionObj->Draw();
	}
	break;
	case eObjType::Enemy:
	{
		CEnemy* actionObj = (CEnemy*)param;
		actionObj->Action();
		actionObj->Draw();
	}
	break;
	case eObjType::Player:
	{
		CPlayer* actionObj = (CPlayer*)param;
		actionObj->Action();
		actionObj->Draw();
	}
	break;
	}
}

void CGameScene::EndProc()
{
	if (_isDead)
	{
		_pMgr->SetNextScene(eSceneType::End);
		//SetReplace();
	}

	if (_enemyNum == 0)
	{
		///////////////////////////////////////////////
		char textBuf[] = "WIN... 3초 뒤 다시 시작합니다";
		memcpy(&g_backBuf[5][5], textBuf, sizeof(textBuf));
		BufferFlip();
		///////////////////////////////////////////////

		// begin QueryPerformanceCounter 구해서 넣는다.
		QueryPerformanceCounter(&_beginTime);

		while (1)
		{
			// end QueryPerformanceCounter 구한다.
			LARGE_INTEGER endTime;
			QueryPerformanceCounter(&endTime);

			// end - begin
			__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

			if ((double)diffTime / _oneSecondFreq > 3)
			{
				_pMgr->SetNextScene(eSceneType::Title);
				break;
			}
		}
	}
}

CGameScene::CGameScene(CSceneManager * pMgr)
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

	// 플레이어 객체 생성
	CBase* newObject = new CPlayer(this);
	_gameList.push_back(newObject);

	// Enemy 초기화
	const int widthDiff = 5;
	const int heightDiff = 3;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			CBase* newEnemy = new CEnemy(this);
			newEnemy->SetPos(30 + widthDiff * j, 5 + heightDiff * i);

			_gameList.push_back(newEnemy);
			_enemyNum++;
		}
	}
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
}

void CGameScene::Update()
{
	// 게임 로직 처리. Action, Draw
	CLinkedList<CBase*>::Iterator nowIter = _gameList.begin();
	CLinkedList<CBase*>::Iterator endIter = _gameList.end();

	BufferClear();
	while (nowIter != endIter)
	{
		// 각 객체 타입에 따른 Action, Draw 호출
		GameProc(*nowIter);

		nowIter++;
	}
	BufferFlip();

	nowIter = _gameList.begin();
	endIter = _gameList.end();

	while (nowIter != endIter)
	{
		CBase* pBase = (*nowIter);
		int tempX = pBase->GetX();
		int tempY = pBase->GetY();

		if (!pBase->CheckPos(tempX, tempY))
		{
			nowIter = _gameList.erase(nowIter);
			delete pBase;
			continue;
		}
		nowIter++;
	}

	// 엔딩 처리
	EndProc();
}

void CGameScene::SetDead()
{
	_isDead = true;
}

CLinkedList<CBase*>* CGameScene::GetListPtr()
{
	return &_gameList;
}

void CGameScene::CreateBullet(eObjType param, int x, int y)
{
	CBase* newBullet = new CBullet(this, param);
	newBullet->SetPos(x, y);

	_gameList.push_back(newBullet);
}