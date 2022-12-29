#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int m, s;
	cin >> m >> s;
	if (m * 9 < s || (s == 0 && m != 1))
	{
		cout << -1 << " " << -1;
		return 0;
	}
	if (s == 0 && m == 1)
	{
		cout << 0 << " " << 0;
		return 0;
	}

	int s3 = s;
	int x = s3 / 9;
	if (s3 % 9 != 0)
	{
		x++;
	}
	for (int i = 1; i <= m; i++)
	{
		if (i <= m - (x))
		{
			if (i == 1)
			{
				cout << 1;
				s3--;
				if ((s3) % 9 == 0)
				{
					x--;
				}
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			if (s3 % 9 != 0)
			{
				cout << s3 % 9;
				i++;
			}
			while (i <= m)
			{
				cout << 9;
				i++;
			}
			break;
			;
		}
	}
	cout << endl;
	int s2 = s;
	for (int i = 1; i <= m; i++)
	{
		if ((s2 - 9) < 0)
		{
			cout << s2 % 9;
			s2 -= s2 % 9;
		}
		if ((s2 - 9) >= 0)
		{
			cout << 9;
			s2 -= 9;
		}
	}
}
