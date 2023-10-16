#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

template <typename T1,typename T2>
class Calc
{
public:
	T1 a;
	T2 b;
	Calc(T1 a, T2 b) {
		this->a = a;
		this->b = b;
	};

	auto Min() {
		return a <= (b) ? a : b;
	};
};

void PrintNum(int num)
{
	printf("%d\n", num);
}
void PrintNum(float num)
{
	printf("%f\n", num);
}
void PrintNum(double num)
{
	printf("%lf\n", num);
}

int main() {
	Calc<int, int> c1(10, 20);
	Calc<int, float> c2(10, 5.1f);
	Calc<int, double> c3(10, 10.1);
	Calc<float, float> c4(1.0f, -0.5f);
	Calc<float, double> c5(2.0f, 10.0);
	Calc<double, double> c6(0.5, 0.45);
	/*int result1 = c1.Min();
	printf("%d\n", result1);
	float result2 = c2.Min();
	printf("%f\n", result2);
	int result3 = c3.Min();
	printf("%d\n", result3);
	float result4 = c4.Min();
	printf("%f\n", result4);
	float result5 = c5.Min();
	printf("%f\n", result5);
	double result6 = c6.Min();
	printf("%lf\n", result6);
	*/
	PrintNum(c1.Min());
	PrintNum(c2.Min());
	PrintNum(c3.Min());
	PrintNum(c4.Min());
	PrintNum(c5.Min());
	PrintNum(c6.Min());

	return 0;
}