#include <stdio.h>
#include <windows.h>
#include <conio.h>

int screenIndex = 0;
HANDLE screen[2];

void Initialize()
{
	CONSOLE_CURSOR_INFO cursor;

	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);
}

void Flip()
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;
}

void Clear()
{
	COORD position = { 0,0 };

	DWORD dword;

	CONSOLE_SCREEN_BUFFER_INFO buffer;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(console, &buffer);

	int width = buffer.srWindow.Right - buffer.srWindow.Left + 1;
	int height = buffer.srWindow.Bottom - buffer.srWindow.Top + 1;

	FillConsoleOutputCharacter
	(
		screen[screenIndex], ' ', width * height, position, &dword
	);
}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

void Render(int x, int y, const char* character)
{
	DWORD dword;
	COORD position = { x,y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], character, strlen(character), &dword, NULL);
}

int main()
{
	int x = 0;
	int y = 0;

	CONSOLE_SCREEN_BUFFER_INFO buffer;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(console, &buffer);

	int width = buffer.srWindow.Right - buffer.srWindow.Left - 2;
	int height = buffer.srWindow.Bottom - buffer.srWindow.Top;

	Initialize();

	Render(x, y, "■");

	while (1)
	{
		Flip();

		Clear();

		char key = _getch();
		if (key == -32 || key == 0)
		{
			key = _getch();

			switch (key)
			{
			case 72: if (y > 0) { y--; }//printf("↑ ");
				   break;
			case 75: if (x > 0) { x -= 2; }//printf("← ");
				   break;
			case 77: if (x < width) { x += 2; }//printf("→ ");
				   break;
			case 80: if (y < height) { y++; }//printf("↓ ");
				   break;
			default: printf("\n무효한 조작\n");
				break;
			}
		}
		else
		{
			printf("\n이건 %c입니다. 방향키를 입력하세요.\n", key);
		}


		Render(x, y, "■");
	}

	return 0;
}