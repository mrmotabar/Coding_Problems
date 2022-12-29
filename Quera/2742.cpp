#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAX_N = 200 + 10, INF = 1ll << 60;
int n, m, k, dp[MAX_N];
set<pair<int, int>> st;
struct mat
{
    int a[MAX_N][MAX_N];
    mat(int x = INF)
    {
        /*for(int i = 0; i < MAX_N; i++){
            fill(a[i], a[i] + MAX_N, INF);
        }*/
        memset(a, 63, sizeof a);
        for (int i = 0; i < MAX_N; i++)
        {
            a[i][i] = x;
        }
    }
    int *operator[](int x)
    {
        return a[x];
    }
};
mat operator*(mat &A, mat &B)
{
    mat ret;
    for (int i = 0; i < MAX_N; i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            ret[i][j] = INF;
            for (int x = 0; x < MAX_N; x++)
            {
                ret[i][j] = min(ret[i][j], A[i][x] + B[x][j]);
            }
        }
    }
    return ret;
}
mat pw(mat A, int b)
{
    mat ret(0);
    while (b)
    {
        if (b & 1)
        {
            ret = ret * A;
        }
        A = A * A;
        b >>= 1;
    }
    return ret;
}
int32_t main()
{
    cin >> n >> m >> k;
    mat adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u][v] = t;
    }
    adj = pw(adj, k);
    memset(dp, 63, sizeof dp);
    dp[1] = 0;
    st.insert({dp[1], 1});
    while (st.size())
    {
        auto v = *st.begin();
        st.erase(st.begin());
        for (int u = 1; u <= n; u++)
        {
            if (v.F + adj[v.S][u] < dp[u])
            {
                st.erase({dp[u], u});
                dp[u] = v.F + adj[v.S][u];
                st.insert({dp[u], u});
            }
        }
    }
    if (dp[n] >= INF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[n] << endl;
}
