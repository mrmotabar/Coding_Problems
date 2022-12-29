#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;
const int MAX_N = 4e4 + 10, sq = 200;
int n, m;
pair<int, pair<int, int>> edge[MAX_N];
vector<int> edms;
vector<pii> adj[MAX_N], query;
bool cmp(int v, int u)
{
    return edge[v].F < edge[u].F;
}
struct mst
{
    int par[MAX_N];
    int get_par(int v)
    {
        return (par[v] == -1 ? v : par[v] = get_par(par[v]));
    }
    void merge(int v, int u)
    {
        int pv = get_par(v);
        int pu = get_par(u);
        if (pu != pv)
        {
            par[pv] = pu;
        }
    }
    void aval()
    {
        memset(par, -1, sizeof par);
        for (int i = 0; i < m; i++)
        {
            if (par[edge[so[i]].S.F] != par[edge[so[i]].S.S])
            {
                merge(edge[so[i]].S.F, edge[so[i]].S.S);
                edms.pb(i);
            }
        }
    }
};
void do_job()
{
    vector<int> kom;
    kom = edms;
    edms.pb()
        query.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        so[i] = i;
        cin >> edge[i].S.F >> edge[i].S.S >> edge[i].F;
        edge[i].S.F--;
        edge[i].S.S--;
        adj[edge[i].S.F].pb({edge[i].S.S, edge[i].F});
        adj[edge[i].S.S].pb({edge[i].S.F, edge[i].F});
    }
    sort(so, so + m, cmp);
    mst.aval();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        query.pb({a, b});
        if (query.size() == sq || i == q - 1)
        {
            do_job();
        }
    }
}
