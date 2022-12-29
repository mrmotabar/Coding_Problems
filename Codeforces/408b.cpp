#include <iostream>
#include <cstdio>
using namespace std;
int a[2][40];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		a[0][int(s1[i]) - int('a')]++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		a[1][int(s2[i]) - int('a')]++;
	}
	int ans = 0;
	for (int i = 0; i < 40; i++)
	{
		if (a[0][i] == 0 && a[1][i] > 0)
		{
			cout << -1;
			return 0;
		}
		ans += min(a[0][i], a[1][i]);
	}
	cout << ans;
}
