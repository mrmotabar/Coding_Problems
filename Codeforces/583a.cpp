/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 50 + 10, INF = 1e9;
int n;
bool as[MAX_N][MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 1; i <= n * n; i++)
	{
		cin >> x >> y;
		if (!as[x][y])
		{
			cout << i << " ";
			for (int j = 1; j <= n; j++)
			{
				as[x][j] = 1;
				as[j][y] = 1;
			}
		}
	}
	cout << endl;
}
