#pragma once

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

// TODO : header include 문제
#include "CLinkedList.h"
class CBase;

class CGameScene : public CScene
{
private:
	// TODO : 멤버 변수로?
	CLinkedList<CBase*> _gameList;

public:
	CGameScene(CSceneManager* pMgr);
	virtual ~CGameScene();

	virtual void Update() override;
	virtual void Replace() override;

	CLinkedList<CBase*>* GetListPtr();
};