#include <stdio.h>

int main()
{
#pragma region 파일 입출력

#pragma region 파일 쓰기
	//매개 변수 1(파일명)
	//매개 변수 2(파일의 입출력 모드)


	FILE* file = fopen("data.txt","w");

	fputs("Character Information\n", file);

	fputs("Health : \n", file);
	fputs("Attack : \n", file);
	fputs("Defence : \n", file);

	fclose(file);

#pragma endregion

#pragma endregion

	return 0;
}