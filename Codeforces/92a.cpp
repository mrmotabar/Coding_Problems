#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	while (true)
	{
		int i = 1;
		while (m >= 0 && i <= n)
		{
			if (m - i == 0)
			{
				cout << 0;
				return 0;
			}
			if (m - i < 0)
			{
				cout << m;
				return 0;
			}
			m -= i;
			i++;
		}
	}
}
