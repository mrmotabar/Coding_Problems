#include <iostream>
#include <cstdio>
using namespace std;
int dp[1000 * 1000 + 10];
int main()
{
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[b - 1] - dp[a - 1] << endl;
	}
}
