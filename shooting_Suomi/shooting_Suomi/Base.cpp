#include "stdafx.h"
#include "Base.h"

eObjType CBase::GetType()
{
	return _type;
}

bool CBase::CheckPos(int x, int y)
{
	// TODO : �̵� ���� üũ

	return false;
}

void CBase::SetPos(int x, int y)
{
	_x = x;
	_y = y;
}
