#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int t = 1;
		while (s[i] == s[i + 1] && t < 5)
		{
			t++;
			i++;
		}
		ans++;
	}
	cout << ans;
}
