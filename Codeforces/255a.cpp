/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, a, b, c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (i % 3 == 0)
		{
			a += x;
		}
		else if (i % 3 == 1)
		{
			b += x;
		}
		else
		{
			c += x;
		}
	}
	if (a > b && a > c)
	{
		cout << "chest" << endl;
	}
	else if (b > a && b > c)
	{
		cout << "biceps" << endl;
	}
	else
	{
		cout << "back" << endl;
	}
}
