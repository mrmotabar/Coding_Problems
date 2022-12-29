#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;
const int MAX_N = 2e2 + 10;
int n, m, num[MAX_N], from[MAX_N], to[MAX_N];
vector<int> adj[MAX_N];
bool mark[MAX_N], vaz[MAX_N];
void dfs(int v, int col)
{
    mark[v] = 1;
    num[v] = col;
    for (int u : adj[v])
    {
        if (!mark[u])
        {
            dfs(u, col);
        }
    }
}
void dfs2(int v)
{
    mark[v] = 1;
    vaz[v] = 1;
    for (int u : adj[v])
    {
        if (!mark[u])
        {
            dfs2(u);
        }
    }
}
void dfs3(int v)
{
    mark[v] = 1;
    for (int u : adj[v])
    {
        if (!mark[u])
        {
            dfs3(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> from[i] >> to[i];
        if (from[i] > to[i])
        {
            swap(from[i], to[i]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            if (from[j] > from[i] && from[j] < to[i] && (to[j] > to[i] || to[j] < from[i]))
            {
                adj[m + i].pb(j);
                adj[j].pb(m + i);
                adj[m + j].pb(i);
                adj[i].pb(m + j);
            }
            else if (from[i] > from[j] && from[i] < to[j] && (to[i] > to[j] || to[i] < from[j]))
            {
                adj[m + j].pb(i);
                adj[i].pb(m + j);
                adj[m + i].pb(j);
                adj[j].pb(m + i);
            }
        }
    }
    int ind = 1;
    for (int i = 1; i <= 2 * m; i++)
    {
        if (!mark[i])
        {
            dfs(i, ind);
            ind++;
        }
    }
    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= 2 * m; i++)
    {
        if (!mark[i])
        {
            dfs2(i);
            dfs3(i + m);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (num[i] == num[m + i])
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (vaz[i])
        {
            cout << "i";
        }
        else
        {
            cout << "o";
        }
    }
}
