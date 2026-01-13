#include <stdio.h>
#include <windows.h>

#define size 10

int main()
{
#pragma region 포인터 배열

	const char* dialog[size];

	dialog[0] = "어서오세요.";
	dialog[1] = "안녕하세요, 탐정님";
	dialog[2] = "무슨 일로 찾아오셨나요?";
	dialog[3] = "조사해주셨으면 하는 일이 있어서요.";
	dialog[4] = "자세한 내용을 알 수 있을까요?";
	dialog[5] = "네 여기...이걸 읽어봐주세요.";
	dialog[6] = "알겠습니다. 흠...으흠? 호오...";
	dialog[7] = "...어떤가요? 가능하실까요?";
	dialog[8] = "네, 해보도록 하죠.";
	dialog[9] = "감사합니다. 잘 부탁드릴게요.";

	//0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태

	//0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태

	//0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태

	//0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태

	//while(1)
	//{
	//	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	//	{
	//		printf("A\n");
	//	}
	//}

	int i = 0;

	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			system("cls");

			if (i < size)
			{
				if (i % 2 == 0)
					printf("탐정 : %s\n", dialog[i]);
				else
					printf("의뢰인 : %s\n", dialog[i]);

				i++;
			}

			else
			{
				printf("다음으로 >>\n");
				break;
			}
		}
		Sleep(10);
	}

#pragma endregion

	return 0;
}