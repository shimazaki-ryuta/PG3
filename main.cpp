#include <stdio.h>
#include <string>
#include <chrono>

using namespace std::chrono;

int main() {
	std::string str(100000,'a');
	std::string cpy,move;
	steady_clock::time_point start = steady_clock::now();
	cpy = str;
	steady_clock::time_point end = steady_clock::now();
	microseconds time = duration_cast<microseconds>(end - start);
	printf("copy : %d\n",int(time.count()));
	start = steady_clock::now();
	move = std::move(str);
	end = steady_clock::now();
	time = duration_cast<microseconds>(end - start);
	printf("move : %d\n", int(time.count()));
	return 0;
}