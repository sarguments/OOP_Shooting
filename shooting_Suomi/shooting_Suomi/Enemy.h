#pragma once

class CGameScene;

class CEnemy : public CBase
{
private:
	CGameScene* _pGameScene;

public:
	//CEnemy();
	CEnemy(CGameScene* pScene);
	virtual ~CEnemy();

	virtual void Action();
	virtual void Draw();

	void Shot();
};