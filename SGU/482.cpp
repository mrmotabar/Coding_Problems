#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int MAX_N = 50 + 10, MAX_H = 100 + 10, MAX_P = 5052 + 10;
int n, h[MAX_N], dp[2][MAX_N][MAX_P];
pair<int, pair<int, int>> par[2][MAX_N][MAX_P];
vector<int> ans;
int ekh[MAX_N], ph[MAX_N];
void pp(int a, int i, int k)
{
    // cout<<a<<" "<<i<<" "<<k<<" "<<dp[a][i][k]<<endl;
    if (dp[a][i][k] == 0)
    {
        return;
    }
    if (a == 0)
    {
        if (par[a][i][k].S.F < i - 1)
        {
            int ind = par[a][i][k].S.F + 1;
            for (int j = i - 1; j >= ind; j--)
            {
                ans.pb(j);
            }
        }
    }
    else
    {
        int ind = par[a][i][k].S.F + 1;
        for (int j = i; j >= ind; j--)
        {
            ans.pb(j);
        }
    }
    if (par[a][i][k].F < 0 || par[a][i][k].S.F < 0 || par[a][i][k].S.S < 0)
    {
        return;
    }
    pp(par[a][i][k].F, par[a][i][k].S.F, par[a][i][k].S.S);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        if (i > 0)
        {
            ekh[i] = ekh[i - 1] + abs(h[i] - h[i - 1]);
            ph[i] = ph[i - 1] + h[i];
        }
        else
        {
            ph[i] = h[i];
            ekh[i] = h[i];
        }
    }
    memset(par, -1, sizeof par);
    for (int i = 2 * (h[0] + 1); i < MAX_P; i++)
    {
        dp[1][0][i] = h[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k < MAX_P; k++)
        {
            dp[0][i][k] = dp[0][i - 1][k];
            par[0][i][k] = {0, {i - 1, k}};
            for (int j = i - 1; j > 0; j--)
            {
                if (k - (2 * (i - j)) - (ekh[i] - ekh[j - 1]) + abs(h[i] - h[j - 1]) >= 0)
                {
                    if (dp[0][j - 1][k - (2 * (i - j)) - (ekh[i] - ekh[j - 1]) + abs(h[i] - h[j - 1])] + (ph[i - 1] - ph[j - 1]) > dp[0][i][k])
                    {
                        dp[0][i][k] = dp[0][j - 1][k - (2 * (i - j)) - (ekh[i] - ekh[j - 1]) + abs(h[i] - h[j - 1])] + (ph[i - 1] - ph[j - 1]);
                        par[0][i][k] = {0, {j - 1, k - (2 * (i - j)) - (ekh[i] - ekh[j - 1]) + abs(h[i] - h[j - 1])}};
                    }
                }
            }
            if (k - (2 * i) - ekh[i] + h[i] >= 0)
            {
                if (ph[i - 1] > dp[0][i][k])
                {
                    dp[0][i][k] = ph[i - 1];
                    par[0][i][k] = {0, {-1, -1}};
                }
            }
            for (int j = i; j > 0; j--)
            {
                if (k - (2 * (i - j + 1)) - (ekh[i] - ekh[j - 1]) - h[i] + h[j - 1] >= 0)
                {
                    if (dp[0][j - 1][k - (2 * (i - j + 1)) - (ekh[i] - ekh[j - 1]) - h[i] + h[j - 1]] + (ph[i] - ph[j - 1]) > dp[1][i][k])
                    {
                        dp[1][i][k] = dp[0][j - 1][k - (2 * (i - j + 1)) - (ekh[i] - ekh[j - 1]) - h[i] + h[j - 1]] + (ph[i] - ph[j - 1]);
                        par[1][i][k] = {0, {j - 1, k - (2 * (i - j + 1)) - (ekh[i] - ekh[j - 1]) - h[i] + h[j - 1]}};
                    }
                }
            }
            if (k - (2 * (i + 1)) - ekh[i] - h[i] >= 0)
            {
                if (ph[i] > dp[1][i][k])
                {
                    dp[1][i][k] = ph[i];
                    par[1][i][k] = {0, {-1, -1}};
                }
            }
        }
    }
    if (dp[1][n - 1][((2 * n) + ekh[n - 1] + h[n - 1]) / 2] > dp[0][n - 1][((2 * n) + ekh[n - 1] + h[n - 1]) / 2])
    {
        cout << dp[1][n - 1][((2 * n) + ekh[n - 1] + h[n - 1]) / 2] << endl;
        pp(1, n - 1, ((2 * n) + ekh[n - 1] + h[n - 1]) / 2);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] + 1 << " ";
        }
    }
    else
    {
        cout << dp[0][n - 1][((2 * n) + ekh[n - 1] + h[n - 1]) / 2] << endl;
        pp(0, n - 1, ((2 * n) + ekh[n - 1] + h[n - 1]) / 2);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] + 1 << " ";
        }
    }
}
