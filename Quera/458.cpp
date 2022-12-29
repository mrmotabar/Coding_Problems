#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAX_N = 500 + 10;
int n, m, w[4][MAX_N][MAX_N], ans, dp[MAX_N][MAX_N], x[4] = {0, +1, 0, -1}, y[4] = {+1, 0, -1, 0};
set<pair<int, pair<int, int>>> st;
int32_t main()
{
    cin >> n >> m;
    for (int k = 0; k < 4; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> w[k][i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int miin = min(w[0][i][j], min(w[1][i][j], min(w[2][i][j], w[3][i][j])));
            ans += miin;
            for (int k = 0; k < 4; k++)
            {
                w[k][i][j] -= miin;
            }
        }
    }
    memset(dp, 63, sizeof dp);
    dp[1][1] = 0;
    st.insert({dp[1][1], {1, 1}});
    while (st.size())
    {
        auto v = *(st.begin());
        st.erase(v);
        for (int p = 0; p < 4; p++)
        {
            if (v.S.F + x[p] >= 1 && v.S.F + x[p] <= n && v.S.S + y[p] >= 1 && v.S.S + y[p] <= m)
            {
                if (v.F + w[p][v.S.F][v.S.S] < dp[v.S.F + x[p]][v.S.S + y[p]])
                {
                    st.erase({dp[v.S.F + x[p]][v.S.S + y[p]], {v.S.F + x[p], v.S.S + y[p]}});
                    dp[v.S.F + x[p]][v.S.S + y[p]] = v.F + w[p][v.S.F][v.S.S];
                    st.insert({dp[v.S.F + x[p]][v.S.S + y[p]], {v.S.F + x[p], v.S.S + y[p]}});
                }
            }
        }
    }
    cout << ans + dp[n][m] << endl;
}
