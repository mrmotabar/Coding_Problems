#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int MAX_N = 2e5 + 10, MOD = 1e9 + 7;
int n, q, a[MAX_N], dp[2][MAX_N], k, d, ind, ans[MAX_N], sum;
vector<pair<int, int>> quer[MAX_N];
int32_t main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i < q; i++)
    {
        cin >> k >> d;
        ind = upper_bound(a + 1, a + n + 1, d) - a;
        ind--;
        quer[ind].pb({min(sum, k * d), i});
    }
    fill(dp[0], dp[0] + sum + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j >= a[i])
            {
                dp[i % 2][j] += dp[(i - 1) % 2][j - a[i]];
            }
            dp[i % 2][j] %= MOD;
        }
        for (auto u : quer[i])
        {
            ans[u.S] = (dp[i % 2][u.F] - 1 + MOD) % MOD;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
}
