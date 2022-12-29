#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	int n, ans = 0;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '<')
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '>')
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans;
}
