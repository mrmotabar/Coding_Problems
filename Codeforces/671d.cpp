#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 3e5 + 10, INF = 9999999;
ll n, m, dis[MAX_N], big[MAX_N], tbus[MAX_N], ans, te;
vector<int> adj[MAX_N];
vector<pair<int, int>> bus[MAX_N];
void pre(int v, int par = 0)
{
    dis[v] = dis[par] + 1;
    tbus[v] = bus[v].size();
    for (int u : adj[v])
    {
        if (u != par)
        {
            pre(u, v);
            tbus[v] += tbus[u];
            if (tbus[u] > tbus[big[v]])
            {
                big[v] = u;
            }
        }
    }
}
int bend[MAX_N];
set<pair<int, int>> st, revst;
void dfs(int v, int par = 0)
{
    vector<pair<int, int>> kom;
    kom.clear();
    bend[v] = dis[v];
    for (int u : adj[v])
    {
        if (u != par && u != big[v])
        {
            dfs(u, v);
            bend[v] = min(bend[v], bend[u]);
            for (auto s : st)
            {
                if (s.S < dis[v])
                {
                    kom.pb({s.F - te, s.S});
                }
            }
            st.clear();
            revst.clear();
            te = 0;
        }
    }
    if (big[v] != 0)
    {
        dfs(big[v], v);
        bend[v] = min(bend[v], bend[big[v]]);
    }
    while (revst.size())
    {
        auto u = *revst.rbegin();
        if (u.F < dis[v])
        {
            break;
        }
        revst.erase(u);
        st.erase({u.S, u.F});
    }
    for (auto u : kom)
    {
        st.insert({u.F + te, u.S});
        revst.insert({u.S, u.F + te});
    }
    for (auto u : bus[v])
    {
        st.insert({u.F + te, dis[u.S]});
        revst.insert({dis[u.S], u.F + te});
    }
    if (bend[v] < dis[v] || v == 1)
    {
        return;
    }
    if (bend[v] == dis[v] && st.size() == 0)
    {
        cout << -1;
        exit(0);
    }
    auto be = *st.begin();
    st.erase(be);
    revst.erase({be.S, be.F});
    ans += be.F - te;
    bend[v] = be.S;
    te = be.F;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for (int i = 0; i < m; i++)
    {
        int v, u, c;
        cin >> v >> u >> c;
        if (v == u)
        {
            continue;
        }
        bus[v].pb({c, u});
    }
    pre(1);
    dfs(1);
    cout << ans;
}
