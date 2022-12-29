#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e5 + 10, MOD = 1e9 + 7;
int n, m, bas, baz;
ll dp[2000 + 20][2000 + 20], ans;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    int temp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            temp++;
        }
        else
        {
            if (temp == 0)
            {
                bas++;
            }
            else
            {
                temp--;
            }
        }
    }
    baz = temp;
    if (baz > 2000 || bas > 2000)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n - m; i++)
    {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        for (int j = 0; j < i && bas + j <= 2000 && baz + j <= 2000; j++)
        {
            ans += (dp[i - 1][bas + j] * dp[n - m - i + 1][baz + j]) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
