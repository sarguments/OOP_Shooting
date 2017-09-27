#pragma once

#include "CLinkedList.h"

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

class CSeneManager;

struct stMatrix
{
	char _ch;
	int _x;
	int _y;
	int _distance;
	int _nFrame;
	int _nStay;
};

class CTitleScene : public CScene
{
private:
	CLinkedList<stMatrix*> _titleList;

public:
	CTitleScene(CSceneManager * pMgr);
	virtual ~CTitleScene();

	virtual void Update();
	//virtual void SetReplace() override;
};