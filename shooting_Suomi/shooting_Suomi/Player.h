#pragma once

// TODO : 전방선언?
class CGameScene;

class CPlayer : public CBase
{
private:
	CGameScene* _pScene;

public:
	CPlayer(CGameScene* pScene);
	virtual ~CPlayer();

	virtual void Action() override;
	virtual void Draw() override;
};