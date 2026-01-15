#include <stdio.h>

#define size 1000

int fs(FILE* file)
{
	int c = 0;
	int s = 0;

	while ((c = fgetc(file)) != EOF)
	{
		s++;
	}
	rewind(file);
	return s;
}

int main()
{
#pragma region 파일 입출력

#pragma region 파일 쓰기
	//매개 변수 1(파일명)
	//매개 변수 2(파일의 입출력 모드)


	//FILE* file = fopen("data.txt","w");
	//
	//fputs("Character Information\n", file);
	//
	//fputs("Health : \n", file);
	//fputs("Attack : \n", file);
	//fputs("Defence : \n", file);
	//
	//fclose(file);

#pragma endregion

#pragma region 파일 읽기

	FILE* file = fopen("data.txt", "r");

	int filesize = fs(file);

	printf("파일의 크기 : %d\n", filesize);
	
	
	char *buffer = calloc(filesize + 1,1);

	//매개 변수 1(저장할 메모리 버퍼의 포인터 변수)
	//매개 변수 2(각 데이터 항목의 크기)
	//매개 변수 3(읽어올 데이터 항목의 개수)
	//매개 변수 4(읽어올 파일의 포인터 변수)

	fread(buffer, sizeof(char), sizeof(buffer), file);

	printf("%s", buffer);

	fclose(file);

#pragma endregion

#pragma endregion

	return 0;
}