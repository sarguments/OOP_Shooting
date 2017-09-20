#pragma once

// �ֻ��� �θ� ��ü
class CBase
{
protected:
	int _x;
	int _y;
	eType _type; // ĳ���� �� �ʿ䵵 ����

	eType GetType();
	bool CheckPos(int x, int y);

public:
	virtual void Action() = 0;
	virtual void Draw() = 0;
};