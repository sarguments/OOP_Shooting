#pragma once

class CGameScene;

class CBullet : public CBase
{
private:
	CGameScene* _pScene;
	// Bullet�� ���� �� �����͸� ��� �ִ´� -> this�� �Ѱ��� �̰ɷ� �÷��̾ ���ʹ̿� ���� ����

	// ���� �� ����
	eObjType _fireObject;
	void HeatScan(CBase* param);

public:
	CBullet(CGameScene* pScene, eObjType param);
	virtual ~CBullet();

	virtual void Action() override;
	virtual void Draw() override;

	eObjType GetFireObj();
};