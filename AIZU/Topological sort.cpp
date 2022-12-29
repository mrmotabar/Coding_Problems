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
deque<int> qu;
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
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
        {
            qu.pb(i);
        }
    }
    while (qu.size())
    {
        int x = qu[0];
        qu.pop_front();
        ans.pb(x);
        for (int u : adj[x])
        {
            deg[u]--;
            if (deg[u] == 0)
            {
                qu.pb(u);
            }
        }
    }
    for (int u : ans)
    {
        cout << u << endl;
    }
}
