/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, a1, b1, c1, n;
	cin >> a >> b >> c >> a1 >> b1 >> c1 >> n;
	a += b + c;
	a1 += b1 + c1;
	int t = (a + 4) / 5 + (a1 + 9) / 10;
	if (t <= n)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
