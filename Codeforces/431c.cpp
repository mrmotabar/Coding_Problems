/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, mod = 1e9 + 7;
int n, k, d;
ll dp[MAX_N], dp2[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> d;
    dp2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            dp2[i] += dp2[i - j];
            dp2[i] %= mod;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= d - 1 && i - j >= 0; j++)
        {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
        for (int j = d; j <= k && i - j >= 0; j++)
        {
            dp[i] += dp2[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
}
