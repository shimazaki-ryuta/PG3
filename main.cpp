#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>


void SetTimeOut(std::function <void()> func, int second)
{
	for (second; second >0; second--)
	{
		printf("*\n");
		Sleep(1000);
	}
	func();
}

int main() {
	int input = 0;
	srand(time(NULL));
	printf("半...0 丁...1 ");
	scanf_s("%d", &input);
	std::function<void()> diceRoll = [=](){
		int answer = rand() % 6 + 1;
		printf("%d", answer);
		if (answer % 2 == (input))
		{
			printf(" 結果 : はずれ\n");
			return;
		}
		printf(" 結果 : 当たり\n");
		return;
	};
	SetTimeOut(diceRoll,3);
	return 0;
}