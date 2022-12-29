#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int n, i = 1, ragh = 1;
	long long int ans = 0;
	cin >> n;
	bool c = true;
	while (c)
	{
		if (n >= i * 9)
		{
			n -= i * 9;
			ans += i * 9 * ragh;
		}
		else
		{
			ans += n * ragh;
			cout << ans;
			c = false;
		}
		i *= 10;
		ragh++;
	}
}
