#include "stdafx.h"
#include "Base.h"
#include "Player.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "CLinkedList.h"

CPlayer::CPlayer(CGameScene* pScene)
{
	_pScene = pScene;

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
	//wprintf(L"�÷��̾� �׼�\n");
}

void CPlayer::Draw()
{
	SpriteDraw(7, 7, 'U');
	BufferFlip();

	/*
		// TODO : �׽�Ʈ
		CLinkedList<CBase*>* listPtr = _pScene->GetListPtr();
		int size = listPtr->size();
		wprintf(L"������ : %d\n", size);

		wprintf(L"�÷��̾� ��ο�\n");
	*/
}