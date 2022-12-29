#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_N = 5e6 + 10, B = 727, MOD = 1e9 + 7;
ll h[2][MAX_N], pw[MAX_N];
int dp[MAX_N], ans;
string s;
ll get(int l, int r, int ind)
{
    return (h[ind][r] - (1ll * h[ind][l] * pw[r - l]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    pw[0] = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        pw[i] = pw[i - 1] * B;
    }
    for (int i = 0; i < s.size(); i++)
    {
        h[0][i + 1] = (1ll * h[0][i] * B + (s[i] - '0' + 1));
        h[1][i + 1] = (1ll * h[1][i] * B + (s[s.size() - 1 - i] - '0' + 1));
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (h[0][(i + 1) / 2] == get(s.size() - 1 - i, s.size() - 1 - ((i + 2) / 2) + 1, 1))
        {
            dp[i] = dp[(i + 1) / 2 - 1] + 1;
            ans += dp[i];
        }
    }
    cout << ans;
}
