/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, baz[600 + 10], bas[600 + 10], payan;
pair<int, int> a[600 * 2 + 100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> baz[i] >> bas[i];
	}
	if (baz[n] > 1)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	string ans = "()";
	for (int i = n - 1; i >= 1; i--)
	{
		if (baz[i] == 1)
		{
			ans = "()" + ans;
		}
		else
		{
			int mot = 0;
			bool g = 0;
			for (int j = 0; j < ans.size() && !g; j++)
			{
				if (ans[j] == '(')
				{
					mot++;
				}
				else
				{
					mot--;
				}
				if (mot == 0 && baz[i] <= j + 2 && bas[i] >= j + 2)
				{
					g = 1;
					ans = '(' + ans;
					ans += ans[ans.size() - 1];
					for (int k = ans.size() - 1; k > j + 2; k--)
					{
						ans[k] = ans[k - 1];
					}
					ans[j + 2] = ')';
				}
				// cout<<mot<<" "<<j<<endl;
			}
			if (!g)
			{
				cout << "IMPOSSIBLE";
				return 0;
			}
		}
	}
	cout << ans;
}
