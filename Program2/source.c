#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int* m, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		int t = m[i];
		m[i] = m[j];
		m[j] = t;
	}
}

int main()
{
#pragma region 의사 난수
	// 0~32767 사이의 난수 값을 반환하는 함수입니다.

	// UTC 기준으로 1970년 1월 1일 0시 0분 0초로부터 경과된 시간을 초로 반환하는 함수입니다.

	// srand : rand()의 초기값을 설정하는 함수

	//srand(time(NULL));
	//
	//int x = rand()%10+1;
	//
	//printf("결과 : %d\n", x);

#pragma endregion

#pragma region 셔플 함수

	int m[] = { 1,2,3,4,5,6,7,8,9,10 };

	srand(time(NULL));
	
	shuffle(m, 10);

	for (int i = 0; i < 10; i++)
	{
		printf(" %d", m[i]);
	}
#pragma endregion


	return 0;
}