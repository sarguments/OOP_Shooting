#pragma once

#include "SceneManager.h"

class CScene
{
protected:
	CSceneManager* _pMgr;
	
public:
	
	virtual void Update() = 0;
	virtual void Replace() = 0;
};

/*

�� ������Ʈ
���Ŀ� �ٲ� ���� ������ ���� �� �����, ���ο� �� ���� ����

�� ��ü
������ �ٲ� ���� ����

*/