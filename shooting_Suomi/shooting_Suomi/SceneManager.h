#pragma once

// TODO : ��� ���� ����
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
