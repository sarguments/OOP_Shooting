#pragma once

class CGameScene;

class CEnemy : public CBase
{
private:
	CGameScene* _pScene;

public:
	//CEnemy();
	CEnemy(CGameScene* pScene);
	virtual ~CEnemy();

	virtual void Action() override;
	virtual void Draw() override;

	void Shot();
};