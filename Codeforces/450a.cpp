#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m, a, ans = 0, max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		int y = a / m;
		if (a % m != 0)
		{
			y++;
		}
		if (y >= max)
		{
			max = y;
			ans = i + 1;
		}
	}
	cout << ans;
}
