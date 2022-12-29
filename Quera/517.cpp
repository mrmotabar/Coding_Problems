#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7, MAX_N = 2e5;
int n, l;
pair<int, int> es[MAX_N];
ll dp[MAX_N], psh[MAX_N], ans;
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> es[i].S >> es[i].F;
    }
    sort(es + 1, es + n + 1);
    dp[0] = 1;
    psh[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ind = lower_bound(es, es + i + 1, make_pair(es[i].S, 0)) - es;
        dp[i] = (psh[i - 1] - psh[ind - 1] + MOD) % MOD;
        psh[i] = (psh[i - 1] + dp[i]) % MOD;
    }
    int i = n;
    while (es[i].F == l)
    {
        ans += dp[i];
        ans %= MOD;
        i--;
    }
    cout << ans;
}
