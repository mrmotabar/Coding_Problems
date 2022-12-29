/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e2 + 10, INF = 1e9;
int n, a[MAX_N], dp[MAX_N][MAX_N], adad[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n)
    {
        memset(dp, 63, sizeof dp);
        memset(adad, 0, sizeof adad);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            adad[i] = adad[i - 1] + a[i];
        }
        for (int i = 1; i <= n - 1; i++)
        {
            dp[i][i + 1] = a[i] * a[i + 1];
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 0;
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = i + 2; j <= n; j++)
            {
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (((adad[k] - adad[i - 1]) % 100) * ((adad[j] - adad[k]) % 100)));
                }
            }
        }
        cout << dp[1][n] << endl;
    }
}
