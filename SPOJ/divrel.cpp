#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int MAX_N = 1e3 + 10;
int n, a[MAX_N], M;
vector<int> adj[MAX_N], adj2[MAX_N], ans;
bool mark[MAX_N], poosh[MAX_N], poosh2[MAX_N];
;
int match[MAX_N], match2[MAX_N];
bool dfs(int v)
{
    mark[v] = 1;
    for (int u : adj[v])
    {
        if (match2[u] == 0 || (!mark[match2[u]] && dfs(match2[u])))
        {
            match[v] = u;
            match2[u] = v;
            return 1;
        }
    }
    return 0;
}
void dfs2(int v)
{
    mark[v] = 1;
    for (int u : adj[v])
    {
        if (!mark[match2[u]])
        {
            poosh2[u] = 1;
            poosh[match2[u]] = 0;
            dfs2(match2[u]);
        }
    }
}
void dfs3(int v)
{
    mark[v] = 1;
    for (int u : adj2[v])
    {
        if (!mark[match[u]])
        {
            poosh[u] = 1;
            poosh2[match[u]] = 0;
            dfs3(match[u]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] % a[i] == 0)
            {
                adj[i].pb(j);
                adj2[j].pb(i);
            }
        }
    }
    while (1)
    {
        bool finished = 1;
        memset(mark, 0, sizeof mark);
        for (int i = 1; i <= n; i++)
        {
            if (!mark[i] && match[i] == 0 && dfs(i))
            {
                M++;
                finished = 0;
            }
        }
        if (finished)
        {
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (match[i] != 0)
        {
            poosh[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(mark, 0, sizeof mark);
        if (match[i] == 0)
        {
            dfs2(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(mark, 0, sizeof mark);
        if (match2[i] == 0)
        {
            dfs3(i);
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<poosh[i]<<"  ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<poosh2[i]<<"  ";
    }*/
    for (int i = 1; i <= n; i++)
    {
        if (!poosh[i] && !poosh2[i])
        {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (int u : ans)
    {
        cout << a[u] << " ";
    }
}
