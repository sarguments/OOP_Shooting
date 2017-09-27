#pragma once

class CSceneManager;

class CScene
{
protected:
	CSceneManager* _pMgr;
	double _oneSecondFreq;
	LARGE_INTEGER _beginTime;

public:
	virtual ~CScene();

	virtual void Update() = 0;
	//virtual void SetReplace() = 0;
};