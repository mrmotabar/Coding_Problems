#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int MAX_N = 1e4 + 10;
int t, t2, n, m;
vector<int> khor[15 + 1][MAX_N], topol;
bool mark[MAX_N];
void dfs(int v)
{
    mark[v] = 1;
    for (int i = 0; i < khor[t2][v].size(); i++)
    {
        int u = khor[t2][v][i];
        if (!mark[u])
        {
            dfs(u);
        }
    }
    topol.pb(v);
}

void dfs2(int v)
{
    mark[v] = 1;
    for (int i = 0; i < khor[t2][v].size(); i++)
    {
        int u = khor[t2][v][i];
        if (!mark[u])
        {
            dfs2(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ans = 0;
        topol.clear();
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            khor[t2][a].pb(b);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!mark[i])
            {
                dfs(i);
            }
        }
        reverse(topol.begin(), topol.end());
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < topol.size(); i++)
        {
            if (!mark[topol[i]])
            {
                dfs2(topol[i]);
                ans++;
            }
        }
        cout << "Case " << t2 + 1 << ": " << ans << endl;
        t2++;
    }
}
