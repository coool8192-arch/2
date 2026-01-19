#include <stdio.h>
#include <windows.h>

enum state
{
	IDLE,
	ATTACK,
	DIE
	// 열거형의 값은 사용자가 정의할 수 있으며, 
	// 하나의 값을 설정하면 그 다음의 값들이 설정값의 다음 수로 설정됩니다.
};

enum color
{
	BLACK, DARKBLUE, DARKGREEN, DARKSKYBLUE, DARKRED, DARKVIOLET, DARKYELLOW, DARKWHITE,
	GRAY, BLUE, GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE
};

void setst(enum state status)
{
	switch (status)
	{
	case IDLE: printf("IDLE\n");
		break;
	case ATTACK: printf("ATTACK\n");
		break;
	case DIE: printf("DEAD\n");
		break;
	default: printf("EXCEPTION\n");
	}
}
int main()
{
#pragma region 열거형
	// 관련된 상수의 값을 이름으로 정의한 집합인 자료형입니다.

	//enum state status;
	//
	//scanf_s("%d", &status);
	//
	//setst(status);
#pragma endregion
	for (int i = 0; i < 16; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		if (i != 0 && i % 4 == 0)
		{
			system("pause");
		}
		printf("color index : %d\n", i);
	}

	return 0;
}