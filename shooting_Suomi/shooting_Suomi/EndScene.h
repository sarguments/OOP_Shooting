#pragma once

class CEndScene: public CScene
{
private:

public:
	CEndScene(CSceneManager * pMgr);
	~CEndScene();
	virtual void Update() override;
	virtual void Replace() override;
};