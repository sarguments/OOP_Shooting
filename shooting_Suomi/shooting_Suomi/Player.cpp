#include "stdafx.h"
#include "Base.h"
#include "Player.h"

CPlayer::CPlayer()
{
	// TODO : �÷��̾� �ʱ�ȭ

	_x = 10;
	_y = 10;
	_type = eObjType::Player;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Action()
{
	wprintf(L"�÷��̾� �׼�\n");
}

void CPlayer::Draw()
{
	wprintf(L"�÷��̾� ��ο�\n");
}