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

	// ���� ����� �˻�
	eObjType fireObj = ((CBullet*)param)->GetFireObj();
	if (fireObj == eObjType::Player)
	{
		// �����Ѿ��̸� ����Ʈ���� ���ʹ̸� ã�´�.
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

			// �Ѿ˰� ���ʹ� ��ġ�� ������ �˻�
			int EnemyPosX = destPtr->GetX();
			int EnemyPosY = destPtr->GetY();

			int BulletPosX = param->GetX();
			int BulletPosY = param->GetY();

			if (EnemyPosX == BulletPosX && EnemyPosY == BulletPosY)
			{
				// ������ ����
				CBase* deleteObj = (*InNowIter);
				InNowIter = ListPtr->erase(InNowIter);
				delete deleteObj;
				_pScene->_enemyNum--;
				continue;
			}
			else
			{
				// �ٸ��� ��ŵ
				InNowIter++;
				continue;
			}
		}
	}
	else
	{
		// �� �Ѿ��̸� ����Ʈ���� �÷��̾ ã�´�
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

			// �Ѿ˰� �÷��̾� ��ġ�� ������ �˻�
			int PlayerPosX = destPtr->GetX();
			int PlayerPosY = destPtr->GetY();

			int BulletPosX = param->GetX();
			int BulletPosY = param->GetY();

			if (PlayerPosX == BulletPosX && PlayerPosY == BulletPosY)
			{
				// ������ ����
				CBase* deleteObj = (*InNowIter);
				InNowIter = ListPtr->erase(InNowIter);
				delete deleteObj;

				// ��� ó��
				_pScene->SetDead();
				return;
			}
			else
			{
				// �ٸ��� ����
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
	// �� �Ѿ��̸� ++ , �÷��̾� �Ѿ��̸� --
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

		// �Ѿ��� �ƴϸ� ��ŵ
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