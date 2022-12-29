#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, b, t;
	cin >> a >> b;
	t = a;
	for (int i = 0; a >= b; i++)
	{
		t += a / b;
		a = a / b + a % b;
	}
	cout << t;
}
