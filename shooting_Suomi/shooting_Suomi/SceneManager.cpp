#include "stdafx.h"
#include "Scene.h"
#include "SceneManager.h"

#include "TitleScene.h"
#include "GameScene.h"
#include "EndScene.h"

// 다음 씬 설정(예약)
void CSceneManager::SetNextScene(eSceneType type)
{
	_eNextScene = type;
}

// 씬 교체
void CSceneManager::Replace()
{
	// 다음 씬이 없으면 리턴
	if (_eNextScene == eSceneType::Blank)
	{
		return;
	}

	if (_nowScene == nullptr)
	{
		return;
	}

	// 기존 씬 삭제
	delete _nowScene;
	
	// 다음 씬 객체 생성해서 _nowScene에 넣는다
	switch (_eNextScene)
	{
	case eSceneType::Title:
	{
		_nowScene = new CTitleScene(this);
		_eNextScene = eSceneType::Blank;
	}
	break;
	case eSceneType::Game:
	{
		_nowScene = new CGameScene(this);
		_eNextScene = eSceneType::Blank;
	}
	break;
	case eSceneType::End:
	{
		_nowScene = new CEndScene(this);
		_eNextScene = eSceneType::Blank;
	}
	break;
	}
}

void CSceneManager::Update()
{
	if (_nowScene == nullptr)
	{
		return;
	}

	_nowScene->Update();
}

CSceneManager::CSceneManager()
{
	// 기본 씬 지정
	_nowScene = new CTitleScene(this);
}

CSceneManager::~CSceneManager()
{
	delete _nowScene;
}
