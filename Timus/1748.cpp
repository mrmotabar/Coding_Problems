#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
ll t, n, p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll po[15][65];
pair<ll, int> ans;
void solve(ll a, int b, int c, int d)
{
    if (c >= 15 || a >= ((n / p[c]) + 1))
    {
        if (ans.S < b || (ans.S == b && ans.F > a))
        {
            ans = {a, b};
        }
        return;
    }
    for (int i = 0; i <= d; i++)
    {
        if (a <= (n / po[c][i]))
        {
            solve(a * po[c][i], b * (i + 1), c + 1, i);
        }
        else
        {
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 15; i++)
    {
        po[i][0] = 1;
        for (int j = 1; j < 65; j++)
        {
            if (po[i][j - 1] > (1e18 / p[i]))
            {
                po[i][j] = 1e18;
            }
            else
            {
                po[i][j] = po[i][j - 1] * p[i];
            }
        }
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = {1, 1};
        solve(1, 1, 0, 64);
        cout << ans.F << " " << ans.S << "\n";
    }
}
