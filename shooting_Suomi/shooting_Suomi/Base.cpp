#include "stdafx.h"
#include "Base.h"

eObjType CBase::GetType()
{
	return _type;
}

int CBase::GetX()
{
	return _x;
}

int CBase::GetY()
{
	return _y;
}

bool CBase::CheckPos(int x, int y)
{
	if (y < 0 || y >(dfSCREEN_HEIGHT - 1) || x < 0 || x >(dfSCREEN_WIDTH - 2))
	{
		return false;
	}

	return true;
}

void CBase::SetPos(int x, int y)
{
	_bornX = x;
	_bornY = y;

	_x = x;
	_y = y;
}