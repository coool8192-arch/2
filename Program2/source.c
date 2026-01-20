#include <stdio.h>
#include <windows.h>
#include <conio.h>

void position(int x, int y)
{
	COORD position = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
int main()
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		char key = _getch();
		if (key == -32 || key == 0)
		{
			key = _getch();

			switch (key)
			{
			case 72:  y--;//printf("↑ ");
				break;
			case 75: x-=2;//printf("← ");
				break;
			case 77: x+=2;//printf("→ ");
				break;
			case 80: y++;//printf("↓ ");
				break;
			default: printf("\n무효한 조작\n");
				break;
			}
		}
		else
		{
			printf("\n이건 %c입니다. 방향키를 입력하세요.\n",key);
		}

		position(x, y);

		if(x>=0&&y>=0)
		{
			printf("■");
		}
	}

	return 0;
}