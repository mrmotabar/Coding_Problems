#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MAX_N = 600 + 10;
ll n, k, t[MAX_N][MAX_N];
ll to[MAX_N][MAX_N], ps[MAX_N][MAX_N], dp[MAX_N][MAX_N], pp[MAX_N][MAX_N];
vector<int> ans;
void ppt(int a, int b)
{
    if (b == 0)
    {
        return;
    }
    ans.pb(pp[a][b]);
    ppt(pp[a][b], b - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> t[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            to[i][j] = to[i - 1][j] + t[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ps[i][j] = ps[i][j - 1] + to[i][j];
        }
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int l = i - 1; l >= 1; l--)
            {
                if (dp[i][j] < ps[l][i] + dp[l][j - 1])
                {
                    dp[i][j] = ps[l][i] + dp[l][j - 1];
                    pp[i][j] = l;
                }
            }
        }
    }
    // cout<<dp[n][k];
    ppt(n, k);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}
