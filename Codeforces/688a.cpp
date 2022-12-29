#include <iostream>
#include <cstdio>
using namespace std;
string s[100000];
int main()
{
	int n, d;
	int maax = 0, m = 0;
	cin >> n >> d;
	for (int i = 0; i < d; i++)
	{
		cin >> s[i];
		bool c = false;
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '0')
			{
				c = true;
				m++;
				break;
			}
		}
		if (c)
		{
			if (m > maax)
			{
				maax = m;
			}
		}
		else
		{
			m = 0;
		}
	}
	cout << maax;
}
