#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAX_N = 1e6 + 10;
int n, m, ans, q[MAX_N], h, t;
set<int> st;
vector<int> mol[MAX_N], adj[MAX_N], del;
bool vis[MAX_N];
void bfs(int v, int ind)
{
    h = 0;
    t = 0;
    q[t++] = v;
    st.erase(v);
    mol[ind].pb(v);
    while (h < t)
    {
        del.clear();
        int x = q[h++];
        int i = 0;
        for (int u : st)
        {
            while (i < adj[x].size() && adj[x][i] < u)
            {
                i++;
            }
            if (adj[x][i] != u || i >= adj[x].size())
            {
                del.pb(u);
            }
        }
        for (int u : del)
        {
            q[t++] = u;
            st.erase(u);
            mol[ind].pb(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        if (st.count(i))
        {
            bfs(i, ans++);
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < ans; i++)
    {
        cout << mol[i].size() << " ";
        for (int u : mol[i])
        {
            cout << u << " ";
        }
        cout << "\n";
    }
}
