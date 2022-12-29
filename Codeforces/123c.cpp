/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e3 + 10, INF = 1e18;
ll k, dp[MAX_N][MAX_N];
short lab[MAX_N], noe[MAX_N], n, m;
pair<int, int> tar[MAX_N];
void filldp()
{
    dp[m + n - 1][0] = 1;
    for (int i = m + n - 2; i >= 1; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (noe[i + 1] == 0)
            {
                dp[i][j] = dp[i + 1][j - 1] + dp[i + 1][j + 1];
            }
            else if (noe[i + 1] == 1)
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            dp[i][j] = min(dp[i][j], INF);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(lab, 31, sizeof lab);
    cin >> n >> m >> k;
    short a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a;
            lab[i + j - 1] = min(lab[i + j - 1], a);
        }
    }
    for (int i = 1; i <= n + m - 1; i++)
    {
        tar[i] = {lab[i], i};
    }
    sort(tar + 1, tar + n + m);
    for (int i = 1; i <= n + m - 1; i++)
    {
        noe[tar[i].S] = 1;
        filldp();
        if (dp[1][1] < k)
        {
            noe[tar[i].S] = 2;
            k -= dp[1][1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (noe[i + j - 1] == 1)
            {
                cout << "(";
            }
            else
            {
                cout << ")";
            }
        }
        cout << endl;
    }
}
