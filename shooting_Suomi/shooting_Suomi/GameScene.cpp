#include "stdafx.h"

#include "Base.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include "Scene.h"
#include "GameScene.h"

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

	if (_isWin)
	{
		///////////////////////////////////////////////
		char temp[] = "WIN... 3�� �� �ٽ� �����մϴ�";
		memcpy(&g_backBuf[5][5], temp, sizeof(temp));
		BufferFlip();
		///////////////////////////////////////////////

		// begin QueryPerformanceCounter ���ؼ� �ִ´�.
		QueryPerformanceCounter(&_beginTime);

		while (1)
		{
			// end QueryPerformanceCounter ���Ѵ�.
			LARGE_INTEGER endTime;
			QueryPerformanceCounter(&endTime);

			// end - begin
			__int64 diffTime = endTime.QuadPart - _beginTime.QuadPart;

			if ((double)diffTime / _oneSecondFreq > 3)
			{
				//wprintf(L"\n5�� ����!!\n");

				_pMgr->SetNextScene(eSceneType::Title);
				break;
			}
		}
	}
}

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

	// �÷��̾� ��ü ����
	CBase* newObject = new CPlayer(this);
	_gameList.push_back(newObject);

	// TODO : Enemy �ʱ�ȭ
	const int widthDiff = 5;
	const int heightDiff = 3;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			CBase* newEnemy = new CEnemy(this);
			//CBase* newEnemy = new CEnemy;
			newEnemy->SetPos(30 + widthDiff * j, 5 + heightDiff * i);

			_gameList.push_back(newEnemy);
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

	if ((double)diffTime / _oneSecondFreq > 5)
	{
		//wprintf(L"\n5�� ����!!\n");

		//Replace();
		_isWin = true;
	}

	/////////////////////////////////////////////////////////////

	// ���� ���� ó��. Action, Draw
	CLinkedList<CBase*>::Iterator nowIter = _gameList.begin();
	CLinkedList<CBase*>::Iterator endIter = _gameList.end();

	BufferClear();
	while (nowIter != endIter)
	{
		// �� ��ü Ÿ�Կ� ���� Action, Draw ȣ��
		GameProc(*nowIter);

		nowIter++;
	}
	BufferFlip();

	// ���� ó��
	EndProc();
}

//void CGameScene::SetReplace()
//{
//	//wprintf(L"Game�� ���÷��̽�\n");
//	_pMgr->SetNextScene(eSceneType::End);
//}

void CGameScene::SetDead() // TODO : �׽�Ʈ��
{
	_isDead = true;
}

CLinkedList<CBase*>* CGameScene::GetListPtr()
{
	return &_gameList;
}

void CGameScene::CreateBullet(eObjType param, int x, int y)
{
	CBase* newBullet = new CBullet(this);
	newBullet->SetPos(x, y);
	_gameList.push_back(newBullet);
}
