#pragma once

class CBullet : public CBase
{
private:
	CScene* _pScene;
	// Bullet이 게임 씬 포인터를 들고 있는다 -> this를 넘겨줌 이걸로 플레이어나 에너미에 접근 가능

public:
	CBullet(CScene* pScene);
	~CBullet();

	virtual void Action() override;
	virtual void Draw() override;
};