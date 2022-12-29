#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAX_N = 1e5 + 10;
int n, a[MAX_N];
map<int, int> mp;
vector<int> adj[MAX_N];
bool vis[MAX_N];
vector<int> root, jaygah[MAX_N], adad[MAX_N];
void dfs(int v, int r)
{
    adad[r].pb(a[v]);
    jaygah[r].pb(v);
    vis[v] = 1;
    for (int u : adj[v])
    {
        if (!vis[u])
        {
            dfs(u, r);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 1)
        {
            mp[a[i]] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            continue;
        }
        adj[i].pb(mp[a[i]]);
        adj[mp[a[i]]].pb(i);
        for (int j = 2; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                if (mp.count(j) > 0)
                {
                    adj[i].pb(mp[j]);
                    adj[mp[j]].pb(i);
                }
                if (mp.count(a[i] / j) > 0)
                {
                    adj[i].pb(mp[a[i] / j]);
                    adj[mp[a[i] / j]].pb(i);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && a[i] != 1)
        {
            root.pb(i);
            dfs(i, i);
        }
    }
    for (int u : root)
    {
        sort(jaygah[u].begin(), jaygah[u].end());
        sort(adad[u].begin(), adad[u].end());
        for (int i = 0; i < jaygah[u].size(); i++)
        {
            a[jaygah[u][i]] = adad[u][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
