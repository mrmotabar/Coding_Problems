#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int t = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '4' || s[j] == '7')
			{
				t++;
			}
		}
		if (t <= k)
		{
			ans++;
		}
	}
	cout << ans;
}
