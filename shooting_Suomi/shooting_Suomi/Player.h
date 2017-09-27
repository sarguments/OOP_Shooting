#pragma once

class CGameScene;

class CPlayer : public CBase
{
private:
	CGameScene* _pGameScene;

public:
	CPlayer(CGameScene* pScene);
	virtual ~CPlayer();

	virtual void Action();
	virtual void Draw();

	void Move(eDir param);
	void KeyProcess();
	void Shot();
};