/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 500 + 10, INF = 1e9;
int n, m, mod, t[MAX_N], t1, t0, en[MAX_N];
ll dp[2][MAX_N][MAX_N];
string c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> mod;
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        for (int j = 0; j < n; j++)
        {
            if (c[j] == '1')
            {
                t[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 1)
            t1++;
        if (t[i] == 0)
            t0++;
    }
    if (t1 & 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        en[i] = (en[i - 1] + i - 1) % mod;
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n - m; i++)
    {
        for (int j = 0; j <= n; j += 2)
        {
            for (int k = 0; k + j <= n; k++)
            {
                if (j >= 2)
                {
                    dp[i & 1][j][k] = (en[j] * dp[(i - 1) & 1][j - 2][k]);
                }
                if (k >= 2)
                {
                    dp[i & 1][j][k] += (en[k] * dp[(i - 1) & 1][j + 2][k - 2]);
                }
                if (j && k)
                {
                    dp[i & 1][j][k] += (((j * k) % mod) * dp[(i - 1) & 1][j][k - 1]);
                }
                dp[i & 1][j][k] %= mod;
            }
        }
    }
    cout << dp[(n - m) & 1][t1][t0] << endl;
}
