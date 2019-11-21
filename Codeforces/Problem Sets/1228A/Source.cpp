#define _CRT_SECURE_NO_WARNING 
#include <iostream>
#include <cstring>
using namespace std;

int posPowerTo(int a, int b);

int main ()
{
	int a = 1;
	int b = 2;
	cout << "Enter two integers: " << a << b;

/*	for (int i = a; i <= r; i++)
	{
		for (int c = 0; c < )
		if (i % 10) i/ (pow(10, c))
	}
*/
}

int posPowerTo(int a, int b)
{
	int sum = 0;
	for (int i = 0; i < b; i++)
	{
		sum += a * a;
	}
	return sum;
}