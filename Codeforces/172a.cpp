#include <iostream>
#include <cstdio>
using namespace std;
string s[10000000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < s[0].size(); i++)
	{
		char c = s[0][i];
		for (int j = 0; j < n; j++)
		{
			if (s[j][i] != c)
			{
				cout << ans;
				return 0;
			}
		}
		ans++;
	}
}
