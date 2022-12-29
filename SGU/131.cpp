/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 9 + 2, INF = 1e9;
ll dp[MAX_N][1 << 12];
ll n, m;
void solve(ll i, ll mask, ll l, ll masgh, ll ind)
{
    if (l == 0)
    {
        dp[i][mask] += dp[i - 1][masgh ^ ((1 << m) - 1)];
        return;
    }
    for (int k = ind; k < m; k++)
    {
        if ((l >> k) & 1)
        {
            if (k + 1 < m && (l >> (k + 1)) & 1)
            {
                // cout<<1;
                solve(i, mask, l ^ (1 << k) ^ (1 << (k + 1)), masgh, k + 1);
            }
            if (k - 1 >= 0 && !((masgh >> k) & 1) && !((masgh >> (k - 1) & 1)))
            {
                // cout<<2;
                solve(i, mask, l ^ (1 << k), masgh ^ (1 << k) ^ (1 << (k - 1)), k + 1);
            }
            if (k + 1 < m && !((masgh >> k) & 1) && !((masgh >> (k + 1)) & 1))
            {
                // cout<<3;
                solve(i, mask, l ^ (1 << k), masgh ^ (1 << k) ^ (1 << (k + 1)), k + 1);
            }
            if (k + 1 < m && (l >> (k + 1)) & 1 && !((masgh >> k) & 1))
            {
                // cout<<4;
                solve(i, mask, l ^ (1 << k) ^ (1 << (k + 1)), masgh ^ (1 << k), k + 1);
            }
            if (k + 1 < m && (l >> (k + 1)) & 1 && !((masgh >> (k + 1)) & 1))
            {
                // cout<<5;
                solve(i, mask, l ^ (1 << k) ^ (1 << (k + 1)), masgh ^ (1 << (k + 1)), k + 1);
            }
            if (!((masgh >> k) & 1))
            {
                // cout<<6;
                solve(i, mask, l ^ (1 << k), masgh ^ (1 << k), k + 1);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    dp[0][(1 << m) - 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int mask = 0; mask < (1 << m); mask++)
        {
            solve(i, mask, mask, 0, 0);
        }
    }
    cout << dp[n][(1 << m) - 1] << endl;
}
