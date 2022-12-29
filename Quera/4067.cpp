/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int zam[6000][6000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(zam, -1, sizeof zam);
	int a = 0, b = 0;
	for (int i = 0; 1; i++)
	{
		if (a > 5000 || b > 5000)
		{
			break;
		}
		zam[a][b] = i;
		if (i % 4 == 0)
		{
			a++;
			b++;
		}
		if (i % 4 == 1)
		{
			a++;
			b--;
		}
		if (i % 4 == 2)
		{
			a++;
			b++;
		}
		if (i % 4 == 3)
		{
			a--;
			b++;
		}
	}
	int t;
	cin >> t;
	int x, y;
	while (t--)
	{
		cin >> x >> y;
		cout << zam[x][y];
		if (t != 0)
		{
			cout << endl;
		}
	}
}
