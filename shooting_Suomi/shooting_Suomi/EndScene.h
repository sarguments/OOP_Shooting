#pragma once

extern char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

class CEndScene : public CScene
{
private:

public:
	CEndScene(CSceneManager * pMgr);
	virtual ~CEndScene();

	virtual void Update() override;
	virtual void Replace() override;
};