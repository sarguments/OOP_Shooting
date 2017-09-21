#pragma once

// TODO : 전방선언?
class CGameScene;

class CEnemy : public CBase
{
private:
	CGameScene* _pScene;

public:
	CEnemy(CGameScene* pScene);
	virtual ~CEnemy();

	virtual void Action() override;
	virtual void Draw() override;
};