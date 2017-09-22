#pragma once

// 최상위 부모 객체
class CBase
{
protected:
	int _x;
	int _y;
	eObjType _type; // 캐스팅 할 필요도 생김

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