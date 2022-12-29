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
int n, k;
vector<int> ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = k; i >= 1; i--)
	{
		for (int j = 0; i + j * k <= n; j++)
		{
			int l = i + j * k;
			if (ans.size() > 0 && abs(l - ans[ans.size() - 1]) < k)
			{
				cout << "Impossible" << endl;
				return 0;
			}
			ans.pb(l);
		}
	}
	for (int u : ans)
	{
		cout << u << " ";
	}
}
