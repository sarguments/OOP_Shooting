#pragma once

class CGameScene;

class CBullet : public CBase
{
private:
	CGameScene* _pScene;
	// Bullet이 게임 씬 포인터를 들고 있는다 -> this를 넘겨줌 이걸로 플레이어나 에너미에 접근 가능

	// 누가 쏜 건지
	eObjType _fireObject;
	void HeatScan(CBase* param);

public:
	CBullet(CGameScene* pScene, eObjType param);
	virtual ~CBullet();

	virtual void Action() override;
	virtual void Draw() override;

	eObjType GetFireObj();
};