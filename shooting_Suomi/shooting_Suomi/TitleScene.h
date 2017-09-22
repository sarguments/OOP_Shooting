#pragma once

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

class CTitleScene : public CScene
{
private:

public:
	CTitleScene(CSceneManager * pMgr);
	virtual ~CTitleScene();

	virtual void Update() override;
	//virtual void SetReplace() override;
};