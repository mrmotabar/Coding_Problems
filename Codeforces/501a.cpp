#include <iostream>
#include <cstdio>
using namespace std;
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (max(3 * a / 10, a - (a / 250) * c) > max(3 * b / 10, b - (b / 250) * d))
	{
		cout << "Misha";
	}
	else if (max(3 * a / 10, a - (a / 250) * c) == max(3 * b / 10, b - (b / 250) * d))
	{
		cout << "Tie";
	}
	else
	{
		cout << "Vasya";
	}
}
