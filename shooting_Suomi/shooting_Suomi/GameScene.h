#pragma once

// TODO : header include ����
#include "CLinkedList.h"
class CBase;

class CGameScene : public CScene
{
private:
	// TODO : ��� ������?
	CLinkedList<CBase*> _gameList; 

public:
	CGameScene(CSceneManager* pMgr);
	virtual ~CGameScene();

	virtual void Update() override;
	virtual void Replace() override;
};