#pragma once

// TODO : ���漱��?
class CScene;

class CBullet : public CBase
{
private:
	CScene* _pScene;
	// Bullet�� ���� �� �����͸� ��� �ִ´� -> this�� �Ѱ��� �̰ɷ� �÷��̾ ���ʹ̿� ���� ����

public:
	CBullet(CScene* pScene);
	virtual ~CBullet();

	virtual void Action() override;
	virtual void Draw() override;
};