#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int s;
	cin >> s;
	int n;
	cin >> n;
	int t = n;
	int o;
	bool c = true;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		cin >> y[i];
		if (x[i] < s)
		{
			x[i] = 0;
			s = s + y[i];
			y[i] = 0;
			t = t - 1;
		}
	}
	for (int i = 0; c == true && t != 0; i++)
	{
		o = s;
		for (int j = 0; j < n; j++)
		{
			if (x[j] < s)
			{
				if (x[j] != 0)
				{
					t = t - 1;
				}
				x[j] = 0;
				s = s + y[j];
				y[j] = 0;
			}
		}
		if (t == 0)
		{
			break;
		}
		if (o == s)
		{
			c = false;
			cout << "NO";
		}
	}
	if (t == 0)
	{
		cout << "YES";
	}
}
