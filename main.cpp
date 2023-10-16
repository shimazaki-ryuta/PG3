#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>


void TimedCall(std::function <void(int)> func, int& input, int second)
{
	for (second; second >0; second--)
	{
		printf("*\n");
		Sleep(1000);
	}
	func(input);
}

int main() {
	int input = 0;
	srand(time(NULL));
	
	std::function<void(int)> func = [](int input){
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

	printf("半...0 丁...1 ");
	scanf_s("%d",&input);
	TimedCall(func,input,3);
	return 0;
}