#pragma once

class CBullet : public CBase
{
private:
	CScene* _pScene;
	// Bullet�� ���� �� �����͸� ��� �ִ´� -> this�� �Ѱ��� �̰ɷ� �÷��̾ ���ʹ̿� ���� ����

public:
	CBullet(CScene* pScene);
	~CBullet();

	virtual void Action() override;
	virtual void Draw() override;
};