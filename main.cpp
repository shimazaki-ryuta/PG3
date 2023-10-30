#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


void ReturnAnswer(int &in)
{
	int answer = rand() % 6 + 1;
	printf("%d",answer);
	if (answer % 2 == (in))
	{
		printf(" 結果 : はずれ\n");
		return;
	}
	printf(" 結果 : 当たり\n");
	return;
}

void SetTimeOut(void (* pFunc)(int &in), int second,int input)
{
	for (second; second >0; second--)
	{
		printf("*\n");
		Sleep(1000);
	}
	pFunc(input);
}

int main() {
	int input = 0;
	srand(time(NULL));
	
	void (*pFunc)(int&);
	pFunc = ReturnAnswer;
	printf("半...0 丁...1 ");
	scanf_s("%d",&input);
	SetTimeOut(pFunc, 3,input);
	return 0;
}