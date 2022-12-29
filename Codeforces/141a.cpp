#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t = 0;
	int a[40], b[40];
	for (int u = 0; u < 40; u++)
	{
		a[u] = 0;
		b[u] = 0;
	}
	string s, v, g;
	cin >> s >> v >> g;
	s += v;
	for (int i = 0; i < s.size(); i++)
	{
		b[int(s[i]) - 65]++;
	}
	for (int i = 0; i < g.size(); i++)
	{
		a[int(g[i]) - 65]++;
	}
	for (int j = 0; j < 40; j++)
	{
		if (a[j] != b[j])
		{
			t++;
		}
	}
	if (t == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
