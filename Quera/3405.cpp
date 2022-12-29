/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int a[1000 + 10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ind = 0;
	while (1)
	{
		cin >> a[ind];
		if (a[ind] == 0)
		{
			ind--;
			break;
		}
		ind++;
	}
	for (int i = ind; i >= 0; i--)
	{
		cout << a[i] << endl;
	}
}
