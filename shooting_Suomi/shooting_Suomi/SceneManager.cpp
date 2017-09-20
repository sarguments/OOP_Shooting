#include "stdafx.h"
#include "Scene.h"
#include "SceneManager.h"

#include "TitleScene.h"
#include "GameScene.h"
#include "EndScene.h"

void CSceneManager::SetNextScene(eSceneType type)
{
	_eNextScene = type;
}

void CSceneManager::Replace()
{
	if (_eNextScene == eSceneType::Blank)
	{
		return;
	}

	if (_nowScene == nullptr)
	{
		return;
	}

	delete _nowScene;
	
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
	// TODO : 기본 씬 지정
	_nowScene = new CTitleScene(this);
}

CSceneManager::~CSceneManager()
{
	delete _nowScene;
}
