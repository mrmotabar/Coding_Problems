#include <iostream>
#include <cstdio>
using namespace std;
void sort(int a[])
{
	for (int i = 0; i < 4; i++)
	{
		int x = a[i];
		int j = i - 1;
		while ((a[j] > x) && (j >= 0))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
int main()
{
	int s[4];
	int t = 0;
	int u = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> s[i];
	}
	sort(s);
	for (int i = 0; i < 4; i++)
	{
		if (s[i] == s[i + 1] && (i + 1) < 4)
		{
			t++;
		}
		else if (s[i] != s[i + 1] && (i + 1) < 4)
		{
			u++;
		}
	}

	cout << t;
}
