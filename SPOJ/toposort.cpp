/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];
set<int> st;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        deg[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            st.insert(i);
        }
    }
    while (st.size())
    {
        int x = *st.begin();
        ans.pb(x);
        st.erase(st.begin());
        for (int u : adj[x])
        {
            deg[u]--;
            if (deg[u] == 0)
            {
                st.insert(u);
            }
        }
    }
    if ((long)ans.size() < n)
    {
        cout << "Sandro fails." << endl;
        return 0;
    }
    for (int u : ans)
    {
        cout << u << " ";
    }
}
