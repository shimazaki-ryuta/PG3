#include <stdio.h>

int calc(int hour,int money)
{
	money = money * 2 - 50;
	if (hour <= 1)
	{
		return money;
	}
	return money + calc(hour-1,money);
}

int main() {

	int hour = 1;
	int money = 100;
	do
	{
		hour++;
		money =(100 +  calc(hour-1, 100))/hour;
		printf("%d時間 ,平均: %d円\n",hour,money);
	} while (1072 > money);
	printf("%d時間働くと再帰的な資金体系のほうが儲かる\n",hour);

	return 0;
}