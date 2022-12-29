#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int m = n / 4;
	for (int i = 0; i <= m; i++)
	{
		int j = n - i * 4;
		if (j % 7 == 0)
		{
			for (int k = 0; k < i; k++)
			{
				cout << 4;
			}
			for (int k = 0; k < j / 7; k++)
			{
				cout << 7;
			}
			return 0;
		}
	}
	cout << -1;
}
