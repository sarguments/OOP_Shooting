#include "stdafx.h"
#include "Base.h"

eObjType CBase::GetType()
{
	return _type;
}

bool CBase::CheckPos(int x, int y)
{
	// TODO : 이동 범위 체크

	return false;
}