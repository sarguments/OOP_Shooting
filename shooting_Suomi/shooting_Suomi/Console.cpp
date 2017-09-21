#include "stdafx.h"
#include "Console.h"

HANDLE  hConsole;

// 백버퍼
char g_backBuf[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

//////////////////////////////////////////////////////////////

void BufferClear()
{
	memset(g_backBuf, 0x20, sizeof(g_backBuf));

	for (int i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		g_backBuf[i][dfSCREEN_WIDTH - 1] = '\0';
	}
}

bool SpriteDraw(int x, int y, char param)
{
	// TODO : 2, 3? 범위체크 먼저
	if (y < 0 || y > dfSCREEN_HEIGHT || x < 0 || x >(dfSCREEN_WIDTH - 1))
	{
		return false;
	}

	g_backBuf[y][x] = param;

	return true;
}

void BufferFlip()
{
	cs_MoveCursor(0, 0);
	for (int i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		cs_MoveCursor(0, i);
		printf("%s", g_backBuf[i]);
	}
}

void PrintText(int x, int y, WCHAR * param)
{
	cs_MoveCursor(x, y);
	wprintf(L"%s\n", param);
}

//////////////////////////////////////////////////////////////

//-------------------------------------------------------------
// 콘솔 제어를 위한 준비 작업.
//
//-------------------------------------------------------------
void cs_Initial(void)
{
	CONSOLE_CURSOR_INFO stConsoleCursor;

	//-------------------------------------------------------------
	// 화면의 커서를 안보이게끔 설정한다.
	//-------------------------------------------------------------
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;			// 커서 크기.
											// 이상하게도 0 이면 나온다. 1로하면 안나온다.

	//-------------------------------------------------------------
	// 콘솔화면 (스텐다드 아웃풋) 핸들을 구한다.
	//-------------------------------------------------------------
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);
}

//-------------------------------------------------------------
// 콘솔 화면의 커서를 X, Y 좌표로 이동시킨다.
//
//-------------------------------------------------------------
void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	//-------------------------------------------------------------
	// 원하는 위치로 커서를 이동시킨다.
	//-------------------------------------------------------------
	SetConsoleCursorPosition(hConsole, stCoord);
}

//-------------------------------------------------------------
// 콘솔 화면을 조기화 한다.
//
//-------------------------------------------------------------
void cs_ClearScreen(void)
{
	int iCountX, iCountY;

	//-------------------------------------------------------------
	// 화면 크기만큼 세로, 가로 이중 for 문을 사용하여
	// 각각의 좌표마다 printf(" ");  공백을 전부 출력 해준다.
	//-------------------------------------------------------------
	for (iCountY = 0; iCountY < dfSCREEN_HEIGHT; iCountY++)
	{
		for (iCountX = 0; iCountX < dfSCREEN_WIDTH; iCountX++)
		{
			cs_MoveCursor(iCountX, iCountY);
			printf(" ");
		}
	}
}