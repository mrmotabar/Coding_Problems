/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, t;
vector<int> adj[MAX_N];
bool vis[MAX_N];
void dfs(int v)
{
    vis[v] = 1;
    for (int u : adj[v])
    {
        if (!vis[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        adj[i].pb(a + i);
    }
    dfs(1);
    if (vis[t])
        cout << "YES";
    else
        cout << "NO";
}
