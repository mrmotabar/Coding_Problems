#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e7 + 10;
long long n, x, y, dp[MAX_N];
int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + x;
        dp[i] = min(dp[i], dp[i / 2 + (i % 2)] + y + ((i % 2) * x));
    }
    cout << dp[n];
}
