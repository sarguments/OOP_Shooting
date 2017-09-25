#pragma once

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

#include "CLinkedList.h"

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

	virtual void Update() override;
	//virtual void SetReplace() override;
};