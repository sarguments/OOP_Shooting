#include "stdafx.h"
#include "Base.h"
#include "Bullet.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "CLinkedList.h"

void CBullet::HeatScan(CBase * param)
{
	CLinkedList<CBase*>* ListPtr = _pScene->GetListPtr();

	// 누가 쏜건지 검사
	eObjType fireObj = ((CBullet*)param)->GetFireObj();
	if (fireObj == eObjType::Player)
	{
		// 유저총알이면 리스트에서 에너미를 찾는다.
		CLinkedList<CBase*>::Iterator InNowIter = ListPtr->begin();
		CLinkedList<CBase*>::Iterator InEndIter = ListPtr->end();

		while (InNowIter != InEndIter)
		{
			CBase* destPtr = (*InNowIter);

			if (destPtr->GetType() != eObjType::Enemy)
			{
				InNowIter++;
				continue;
			}

			// 총알과 에너미 위치가 같은지 검사
			int EnemyPosX = destPtr->GetX();
			int EnemyPosY = destPtr->GetY();

			int BulletPosX = param->GetX();
			int BulletPosY = param->GetY();

			if (EnemyPosX == BulletPosX && EnemyPosY == BulletPosY)
			{
				// 같으면 삭제
				CBase* deleteObj = (*InNowIter);
				InNowIter = ListPtr->erase(InNowIter);
				delete deleteObj;
				_pScene->_enemyNum--;
				continue;
			}
			else
			{
				// 다르면 스킵
				InNowIter++;
				continue;
			}
		}
	}
	else
	{
		// 적 총알이면 리스트에서 플레이어를 찾는다
		CLinkedList<CBase*>::Iterator InNowIter = ListPtr->begin();
		CLinkedList<CBase*>::Iterator InEndIter = ListPtr->end();

		while (InNowIter != InEndIter)
		{
			CBase* destPtr = (*InNowIter);

			if (destPtr->GetType() != eObjType::Player)
			{
				InNowIter++;
				continue;
			}

			// 총알과 플레이어 위치가 같은지 검사
			int PlayerPosX = destPtr->GetX();
			int PlayerPosY = destPtr->GetY();

			int BulletPosX = param->GetX();
			int BulletPosY = param->GetY();

			if (PlayerPosX == BulletPosX && PlayerPosY == BulletPosY)
			{
				// 같으면 삭제
				CBase* deleteObj = (*InNowIter);
				InNowIter = ListPtr->erase(InNowIter);
				delete deleteObj;

				// 사망 처리
				_pScene->SetDead();
				return;
			}
			else
			{
				// 다르면 리턴
				return;
			}
		}
	}
}

CBullet::CBullet(CGameScene * pScene, eObjType param)
{
	_pScene = pScene;

	_type = eObjType::Bullet;
	_fireObject = param;
}

CBullet::~CBullet()
{
}

void CBullet::Action()
{
	// 적 총알이면 ++ , 플레이어 총알이면 --
	if (_fireObject == eObjType::Enemy)
	{
		_y++;
	}
	else
	{
		_y--;
	}

	/////////////////////////////////

	CLinkedList<CBase*>* ListPtr = _pScene->GetListPtr();

	CLinkedList<CBase*>::Iterator nowIter = ListPtr->begin();
	CLinkedList<CBase*>::Iterator endIter = ListPtr->end();

	while (nowIter != endIter)
	{
		CBase* ObjPtr = (*nowIter);

		// 총알이 아니면 스킵
		if (ObjPtr->GetType() != eObjType::Bullet)
		{
			nowIter++;
			continue;
		}

		HeatScan(ObjPtr);

		nowIter++;
	}
}

void CBullet::Draw()
{
	SpriteDraw(_x, _y, 'i');
}

eObjType CBullet::GetFireObj()
{
	return _fireObject;
}