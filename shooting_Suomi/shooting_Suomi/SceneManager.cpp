#include "stdafx.h"
#include "Scene.h"
#include "SceneManager.h"

#include "TitleScene.h"
#include "GameScene.h"
#include "EndScene.h"

void CSceneManager::Replace()
{
}

void CSceneManager::Update()
{
}

CSceneManager::CSceneManager()
{
	// TODO : 기본 씬 지정
	_nextScene = nullptr;
	_nowScene = new CGameScene;
}

CSceneManager::~CSceneManager()
{
}
