#pragma once

// TODO : ���漱��?
class CGameScene;

class CBullet : public CBase
{
private:
	CGameScene* _pScene;
	// Bullet�� ���� �� �����͸� ��� �ִ´� -> this�� �Ѱ��� �̰ɷ� �÷��̾ ���ʹ̿� ���� ����

public:
	CBullet(CGameScene* pScene);
	virtual ~CBullet();

	virtual void Action() override;
	virtual void Draw() override;
};