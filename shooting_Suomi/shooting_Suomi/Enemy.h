#pragma once

// TODO : 전방선언?
class CGameScene;

class CEnemy : public CBase
{
private:
	CGameScene* _pScene;
	//int _bornX;
	//int _bornY;
	//eDir _dir;

public:
	//CEnemy();
	CEnemy(CGameScene* pScene);
	virtual ~CEnemy();

	virtual void Action() override;
	virtual void Draw() override;
};