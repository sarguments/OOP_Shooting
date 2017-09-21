#include "stdafx.h"
#include "SceneManager.h"

CSceneManager g_SceneMgr;

int main()
{
	setlocale(LC_ALL, "");
	cs_Initial();

	while (1)
	{
		g_SceneMgr.Replace();
		g_SceneMgr.Update();
	}

	return 0;
}