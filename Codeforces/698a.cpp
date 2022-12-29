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
int n, a[MAX_N], dp[MAX_N][3 + 2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 63, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] == 0)
    {
        dp[1][0] = 1;
    }
    if (a[1] == 1)
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    if (a[1] == 2)
    {
        dp[1][0] = 1;
        dp[1][2] = 0;
    }
    if (a[1] == 3)
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 0)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);
        }
        else if (a[i] == 1)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][2]);
        }
        else if (a[i] == 2)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);
            dp[i][2] = min(dp[i][2], dp[i - 1][0]);
            dp[i][2] = min(dp[i][2], dp[i - 1][1]);
        }
        else
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][2]);
            dp[i][2] = min(dp[i][2], dp[i - 1][0]);
            dp[i][2] = min(dp[i][2], dp[i - 1][1]);
        }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}
