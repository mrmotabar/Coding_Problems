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
int a[10 + 2], x;
bool boo;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		a[x]++;
		if (a[x] >= 4)
		{
			boo = true;
			a[x] -= 4;
		}
	}
	if (!boo)
	{
		cout << "Alien" << endl;
		return 0;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (a[i] == 2)
		{
			cout << "Elephant" << endl;
			return 0;
		}
	}
	cout << "Bear" << endl;
}
