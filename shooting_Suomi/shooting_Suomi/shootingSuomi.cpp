#include "stdafx.h"
#include "SceneManager.h"

CSceneManager g_SceneMgr;

int main()
{
	setlocale(LC_ALL, "");
	cs_Initial();

	while (1)
	{
		g_SceneMgr.SetReplace();
		g_SceneMgr.Update();

		Sleep(10);
	}

	return 0;
}