#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, s = 0;
	cin >> a >> b >> c;
	for (int i = 0; i < 10000 && s == 0; i++)
	{
		for (int j = 0; j < 10000 && s == 0; j++)
		{
			if (a * j + b * i == c)
				s = 1;
		}
	}
	if (s == 1)
		cout << "YES";
	else
		cout << "NO";
}
