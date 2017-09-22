#pragma once

// �ֻ��� �θ� ��ü
class CBase
{
protected:
	int _x;
	int _y;
	eObjType _type; // ĳ���� �� �ʿ䵵 ����

	int _bornX;
	int _bornY;
	eDir _dir;

public:
	virtual void Action() = 0;
	virtual void Draw() = 0;

	void SetPos(int x, int y);
	bool CheckPos(int x, int y);
	eObjType GetType();
};