/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 2e3 + 10, INF = 1e9, mod = 1e9 + 7;
int n, k, dp[MAX_N][MAX_N], ans;
vector<int> magh[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j * i <= 2000; j++)
        {
            magh[i * j].pb(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            for (int u : magh[i])
            {
                dp[j][i] += dp[j - 1][u];
                dp[j][i] %= mod;
            }
        }
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;
}
