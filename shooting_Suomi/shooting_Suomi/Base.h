#pragma once

// 최상위 부모 객체
class CBase
{
protected:
	int _x;
	int _y;
	eType _type; // 캐스팅 할 필요도 생김

	eType GetType();
	bool CheckPos(int x, int y);

public:
	virtual void Action() = 0;
	virtual void Draw() = 0;
};