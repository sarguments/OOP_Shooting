#pragma once

// TODO : 헤더 포함 문제
class CScene;

class CSceneManager
{
private:
	CScene* _nextScene;
	CScene* _nowScene;

	void Replace();
	void Update();

public:
	CSceneManager();
	~CSceneManager();

};
