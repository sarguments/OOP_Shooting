#pragma once

#include "CLinkedList.h"

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

class CBase;
class CSceneManager;

class CGameScene : public CScene
{
private:
	CLinkedList<CBase*> _gameList;

	// ав╬ЗЁд
	bool _isDead = false;

	void GameProc(CBase* param);
	void EndProc();

public:
	CGameScene(CSceneManager* pMgr);
	virtual ~CGameScene();

	virtual void Update();
	//virtual void SetReplace() override;

	CLinkedList<CBase*>* GetListPtr();

	void SetDead();
	void CreateBullet(eObjType param, int x, int y);

	int _enemyNum = 0;
};