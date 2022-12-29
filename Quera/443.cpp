#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 5e4 + 1, INF = (1 << 31);
int n, m, t, k, a[MAX_N], ans;
vector<pii> adj[MAX_N];
set<pii> st;
int dp[MAX_N];
inline void dij(int v)
{
    if (dp[v] >= k)
    {
        ans--;
    }
    dp[v] = 0;
    st.insert({dp[v], v});
    while (st.size())
    {
        pii x = *st.begin();
        st.erase(st.begin());
        for (pii u : adj[x.S])
        {
            if (x.F + u.S < dp[u.F])
            {
                if (x.F + u.S < k && dp[u.F] >= k)
                {
                    ans--;
                }
                st.erase({dp[u.F], u.F});
                dp[u.F] = x.F + u.S;
                st.insert({dp[u.F], u.F});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t >> k;
    ans = n;
    fill(dp, dp + n + 1, 101);
    int v, u, w;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> u >> w;
        adj[v].pb({u, w});
        adj[u].pb({v, w});
    }
    for (int i = 1; i <= t; i++)
    {
        cin >> a[i];
        dij(a[i]);
        cout << ans << "\n";
    }
}
