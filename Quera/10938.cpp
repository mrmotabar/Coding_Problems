/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 65536 + 10, INF = 1e9, maxl = 17;
ll n, a[MAX_N], dp[(1 << maxl) + 10], mark[(1 << maxl) + 10], t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            t++;
    }
    if (t > 0)
    {
        cout << n - t << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        mark[a[i]] = 1;
    }
    for (int mask = 0; mask < (1 << maxl); mask++)
    {
        for (int i = 0; i < maxl; i++)
        {
            if (!((mask >> i) & 1))
            {
                mark[mask + (1 << i)] |= mark[mask];
            }
        }
    }
    memset(dp, 63, sizeof dp);
    dp[0] = 0;
    int x = (1 << maxl) - 1;
    for (int mask = 1; mask < (1 << maxl); mask++)
    {
        for (int smask = mask; smask; smask = (smask - 1) & mask)
        {
            if (mark[x - (mask ^ smask)])
            {
                dp[mask] = min(dp[mask], dp[smask] + 1);
            }
        }
        if (mark[x - (mask ^ 0)])
        {
            dp[mask] = min(dp[mask], dp[0] + 1);
        }
    }
    ll mi = INF;
    for (int i = 1; i <= n; i++)
    {
        mi = min(dp[a[i]], mi);
    }
    cout << n - 1 + mi << endl;
}
