#include <stdio.h>

int main() {
	int end_flg = 0;



	printf("\nコンソールアプリケーションを終了する場合は数字の1を入力しEnterキーを押してください");
	scanf_s("%d",&end_flg);
	if (end_flg == 1)return 0;
	else return -1;
}