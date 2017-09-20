#include "stdafx.h"
#include "SceneManager.h"

CSceneManager g_SceneMgr;

int main()
{
	setlocale(LC_ALL, "");
	cs_Initial();

	cs_MoveCursor(30, 10);
	wprintf(L"메인이다아아\n");

	while (1)
	{
		g_SceneMgr.Replace();
		g_SceneMgr.Update();
	}

    return 0;
}
