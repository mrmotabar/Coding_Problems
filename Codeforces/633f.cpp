#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e5 + 10;
int n, a[MAX_N], dpdown[2][MAX_N], dpup[2][MAX_N];
pair<int, int> chl[MAX_N];
vector<int> adj[MAX_N];
void dfsdown(int v, int par = 0)
{
    int maax1 = 0, maax2 = 0;
    for (int u : adj[v])
    {
        if (u != par)
        {
            dfsdown(u, v);
            if (dpdown[0][u] >= chl[v].F)
            {
                chl[v].S = chl[v].F;
                chl[v].F = dpdown[0][u];
            }
            else if (dpdown[0][u] > chl[v].S)
            {
                chl[v].S = dpdown[0][u];
            }
            if (dpdown[1][u] >= maax1)
            {
                maax2 = maax1;
                maax1 = dpdown[1][u];
            }
            else if (dpdown[1][u] > maax2)
            {
                maax2 = dpdown[1][u];
            }
        }
    }
    dpdown[1][v] = maax1 + a[v];
    dpdown[0][v] = max(chl[v].F, maax1 + a[v] + maax2);
}
void dfsup(int v, int par = 0)
{
    cout << v << endl;
    pair<int, int> pshl[MAX_N], pshr[MAX_N];
    pshl[1].F = dpdown[1][adj[v][0]];
    pshl[1].S = 0;
    pshr[adj[v].size()].F = dpdown[1][adj[v][adj[v].size() - 1]];
    pshr[adj[v].size()].S = 0;
    for (int i = 2; i <= adj[v].size(); i++)
    {
        if (adj[v][i - 1] == par)
        {
            pshl[i] = pshl[i - 1];
        }
        else
        {
            pshl[i] = pshl[i - 1];
            if (dpdown[1][adj[v][i - 1]] >= pshl[i].F)
            {
                pshl[i].S = pshl[i].F;
                pshl[i].F = dpdown[1][adj[v][i - 1]];
            }
            else if (dpdown[1][adj[v][i - 1]] > pshl[i].S)
            {
                pshl[i].S = dpdown[1][adj[v][i - 1]];
            }
        }
    }
    for (int i = adj[v].size() - 1; i >= 1; i--)
    {
        if (adj[v][i - 1] == par)
        {
            pshl[i] = pshl[i + 1];
        }
        else
        {
            pshl[i] = pshl[i + 1];
            if (dpdown[1][adj[v][i - 1]] >= pshl[i].F)
            {
                pshl[i].S = pshl[i].F;
                pshl[i].F = dpdown[1][adj[v][i - 1]];
            }
            else if (dpdown[1][adj[v][i - 1]] > pshl[i].S)
            {
                pshl[i].S = dpdown[1][adj[v][i - 1]];
            }
        }
    }
    for (int i = 1; i <= adj[v].size(); i++)
    {
        if (adj[v][i - 1] != par)
        {
            pair<int, int> maax;
            int k[5] = {pshl[i - 1].F, pshl[i - 1].S, pshr[i + 1].F, pshr[i + 1].S, dpup[1][v]};
            sort(k, k + 5);
            maax.F = k[4];
            maax.S = k[3];
            dpup[1][adj[v][i - 1]] = max(dpup[1][v], maax.F + a[v]) + a[adj[v][i - 1]];
            dpup[0][adj[v][i - 1]] = max(dpup[0][v], maax.F + a[v] + maax.S);
            cout << adj[v][i - 1] << endl;
            dfsup(adj[v][i - 1], v);
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
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfsdown(1);
    dfsup(1);
    cout << dpup[0][1] << endl;
}
