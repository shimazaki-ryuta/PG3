#include <stdio.h>

template <typename Type>
Type Min(Type a, Type b)
{
	return a < b ? a : b;
}

char* Min(char a,char b)
{
	static char string[] = "数字以外は代入できません";
	printf("%s\n",string);
	return string;
}

int main() {

	int int1 = 2, int2 = 5;
	float float1 = 1.0f, float2 = -1.2f;
	double double1 = 0.5, double2 = 2.8;
	char char1 = 'a', char2 = 'b';
	printf("%d\n", Min(int1, int2));
	printf("%f\n", Min(float1, float2));
	printf("%lf\n", Min(double1, double2));
	//printf("%s\n", Min(char1, char2));
	Min(char1, char2);
	return 0;
}