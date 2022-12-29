/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, x[MAX_N], h[MAX_N], dp[MAX_N][3 + 5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> h[i];
    }
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (x[i - 1] + h[i - 1] < x[i])
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
            dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + 1;
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        }
        if (x[i] - h[i] > x[i - 1])
        {
            if (x[i - 1] + h[i - 1] < x[i] - h[i])
            {
                dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + 1;
            }
            else
            {
                dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            }
        }
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}
