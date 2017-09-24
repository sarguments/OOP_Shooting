#pragma once

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

// TODO : header include ����
#include "CLinkedList.h"
class CBase;

class CGameScene : public CScene
{
private:
	// TODO : ��� ������?
	CLinkedList<CBase*> _gameList;

	// �׾���
	bool _isDead = false;

	void GameProc(CBase* param);
	void EndProc();

public:
	CGameScene(CSceneManager* pMgr);
	virtual ~CGameScene();

	virtual void Update() override;
	//virtual void SetReplace() override;

	void SetDead();

	CLinkedList<CBase*>* GetListPtr();

	void CreateBullet(eObjType param, int x, int y);

	int _enemyNum = 0;
};