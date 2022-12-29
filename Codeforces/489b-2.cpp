#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 2e2 + 10;
int n, m, a[MAX_N], b[MAX_N], ans;
vector<int> adj[MAX_N], adj2[MAX_N];
int match[MAX_N], match2[MAX_N];
bool mark[MAX_N];
bool dfs(int v)
{
    mark[v] = true;
    for (int u : adj[v])
    {
        if (match2[u] == -1 || (!mark[match2[u]] && dfs(match2[u])))
        {
            match2[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (abs(a[i] - b[j]) <= 1)
            {
                adj[i].pb(j);
                adj2[j].pb(i);
            }
        }
    }
    memset(match, -1, sizeof match);
    memset(match2, -1, sizeof match2);
    while (1)
    {
        bool finished = true;
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < n; i++)
        {
            if (!mark[i] && match[i] == -1 && dfs(i))
            {
                ans++;
                finished = false;
            }
        }
        if (finished)
        {
            break;
        }
    }
    cout << ans;
}
