#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int pour(int A, int B, int C)
{
	int ans = 1, a = A, b = 0, temp;
	while (a != C && b != C)
	{
		temp = min(a, B - b);
		b += temp;
		a -= temp;
		ans++;
		if (a == C || b == C)
		{
			break;
		}
		if (a == 0)
		{
			a = A;
			ans++;
		}
		if (b == B)
		{
			b = 0;
			ans++;
		}
	}
	return ans;
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	int t, a, b, c;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c;
		if (c > a && c > b)
		{
			cout << -1 << endl;
		}
		else if (c % gcd(a, b) != 0)
		{
			cout << -1 << endl;
		}
		else if (c == a || c == b)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << min(pour(a, b, c), pour(b, a, c)) << endl;
		}
	}
}
