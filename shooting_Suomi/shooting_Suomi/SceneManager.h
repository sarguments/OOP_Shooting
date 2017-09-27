#pragma once

class CScene;

class CSceneManager
{
private:
	eSceneType _eNextScene = eSceneType::Blank;
	CScene* _nowScene;

public:
	CSceneManager();
	~CSceneManager();

	void SetNextScene(eSceneType type);
	void SetReplace();
	void Update();
};
