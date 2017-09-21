#include "stdafx.h"
#include "Console.h"

HANDLE  hConsole;

// �����
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
	// TODO : 2, 3? ����üũ ����
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
// �ܼ� ��� ���� �غ� �۾�.
//
//-------------------------------------------------------------
void cs_Initial(void)
{
	CONSOLE_CURSOR_INFO stConsoleCursor;

	//-------------------------------------------------------------
	// ȭ���� Ŀ���� �Ⱥ��̰Բ� �����Ѵ�.
	//-------------------------------------------------------------
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;			// Ŀ�� ũ��.
											// �̻��ϰԵ� 0 �̸� ���´�. 1���ϸ� �ȳ��´�.

	//-------------------------------------------------------------
	// �ܼ�ȭ�� (���ٴٵ� �ƿ�ǲ) �ڵ��� ���Ѵ�.
	//-------------------------------------------------------------
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);
}

//-------------------------------------------------------------
// �ܼ� ȭ���� Ŀ���� X, Y ��ǥ�� �̵���Ų��.
//
//-------------------------------------------------------------
void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	//-------------------------------------------------------------
	// ���ϴ� ��ġ�� Ŀ���� �̵���Ų��.
	//-------------------------------------------------------------
	SetConsoleCursorPosition(hConsole, stCoord);
}

//-------------------------------------------------------------
// �ܼ� ȭ���� ����ȭ �Ѵ�.
//
//-------------------------------------------------------------
void cs_ClearScreen(void)
{
	int iCountX, iCountY;

	//-------------------------------------------------------------
	// ȭ�� ũ�⸸ŭ ����, ���� ���� for ���� ����Ͽ�
	// ������ ��ǥ���� printf(" ");  ������ ���� ��� ���ش�.
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