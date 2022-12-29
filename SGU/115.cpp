#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n, m, t = 1;
	cin >> n >> m;
	if (m > 12 || n > 31)
	{
		cout << "Impossible";
		return 0;
	}
	if ((m == 1 && n > 31) || (m == 2 && n > 28) || (m == 3 && n > 31) || (m == 4 && n > 30) || (m == 5 && n > 31) || (m == 6 && n > 30) || (m == 7 && n > 31) || (m == 8 && n > 31) || (m == 9 && n > 30) || (m == 10 && n > 31) || (m == 11 && n > 30) || (m == 12 && n > 31))
	{
		cout << "Impossible";
	}
	for (int i = 1; i < m; i++)
	{
		if (i == 1)
		{
			t += 31;
		}
		else if (i == 2)
		{
			t += 28;
		}
		else if (i == 3)
		{
			t += 31;
		}
		else if (i == 4)
		{
			t += 30;
		}
		else if (i == 5)
		{
			t += 31;
		}
		else if (i == 6)
		{
			t += 30;
		}
		else if (i == 7)
		{
			t += 31;
		}
		else if (i == 8)
		{
			t += 31;
		}
		else if (i == 9)
		{
			t += 30;
		}
		else if (i == 10)
		{
			t += 31;
		}
		else if (i == 11)
		{
			t += 30;
		}
		else if (i == 12)
		{
			t += 31;
		}
	}
	t += n - 1;
	t %= 7;
	if (t == 0)
	{
		cout << 7;
	}
	else
	{
		cout << t;
	}
}
