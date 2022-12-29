#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int y = int(s1[i]) - int(s2[i]);
		if (y < 0)
		{
			y *= -1;
		}
		int x = 10 - y;
		if (x < 0)
		{
			x *= -1;
		}
		ans += min(y, x);
	}
	cout << ans;
}
