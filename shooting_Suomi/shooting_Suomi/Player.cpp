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

	// TODO : 플레이어 초기화
	_x = 10;
	_y = 10;
	_type = eObjType::Player;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Action()
{
	//wprintf(L"플레이어 액션\n");
	_x++;
}

void CPlayer::Draw()
{
	SpriteDraw(_x, _y, 'U');
	//BufferFlip();

	/*
		// TODO : 테스트
		CLinkedList<CBase*>* listPtr = _pScene->GetListPtr();
		int size = listPtr->size();
		wprintf(L"사이즈 : %d\n", size);

		wprintf(L"플레이어 드로우\n");
	*/
}