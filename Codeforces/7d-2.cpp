#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e6 + 10;
string s, rev;
int dp[MAX_N], f[MAX_N], ans;
bool pal[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    rev = s;
    reverse(rev.begin(), rev.end());
    int cur = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (cur && s[cur] != s[i])
        {
            cur = f[cur];
        }
        cur += (s[cur] == s[i]);
        f[i + 1] = cur;
    }
    for (int i = 0; i < s.size(); i++)
    {
        while (cur && s[cur] != rev[i])
        {
            cur = f[cur];
        }
        cur += (s[cur] == rev[i]);
    }
    while (cur)
    {
        pal[cur] = 1;
        cur = f[cur];
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (pal[i + 1])
        {
            dp[i] = dp[(i + 1) / 2 - 1] + 1;
            ans += dp[i];
        }
    }
    cout << ans;
}
