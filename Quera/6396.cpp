/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 100, INF = 1e9;
ll n, dis[MAX_N], root;
vector<int> adj[MAX_N];
void dfs(int v, int p = 0)
{
    dis[v] = dis[p] + 1;
    if (dis[v] > dis[root])
        root = v;
    for (int u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    dfs(root);
    cout << dis[root] - 1 << "  " << (n * (n - 1)) / 2 << endl;
}
