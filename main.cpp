#include <stdio.h>
#include <thread>

void PrintThreadNum(int num) {
	printf("thread %d\n",num);
}

int main() {
	int num = 0;
	std::thread thread1(PrintThreadNum, ++num);
	thread1.join();
	std::thread thread2(PrintThreadNum, ++num);
	thread2.join();
	std::thread thread3(PrintThreadNum, ++num);

	thread3.join();
	return 0;
}