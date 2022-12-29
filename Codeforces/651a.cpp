#include <iostream>
#include <cstdio>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	while (a > 0)
	{
		a++;
		b -= 2;
		c++;
		if (a > b)
		{
			swap(a, b);
		}
	}
	if (a < 0)
	{
		c--;
	}
	cout << c;
}
