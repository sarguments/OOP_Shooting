#pragma once

class CTitleScene : public CScene
{
private:

public:
	CTitleScene(CSceneManager * pMgr);
	virtual ~CTitleScene();

	virtual void Update() override;
	virtual void Replace() override;
};