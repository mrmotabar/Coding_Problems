#include <bits/stdc++.h>
using namespace std;
int a[40][40], dp[40][40], ans;
int main()
{
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for (int i = 2; i <= 15; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
