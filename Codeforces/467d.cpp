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
int n, q, indk = 1;
string s[MAX_N];
vector<ll> topol;
bool mark[MAX_N], vis[MAX_N];
vector<pair<string, string>> yal;
vector<string> hlp;
ll tr[MAX_N], num[MAX_N], numi;
vector<ll> adjkhor[MAX_N], adjvor[MAX_N];
pll anmol[MAX_N];
int cntr(string v)
{
    int ret = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 'r')
        {
            ret++;
        }
    }
    return ret;
}
string lower(string v)
{
    string ret = v;
    for (int i = 0; i < ret.size(); i++)
    {
        if (int(ret[i]) >= int('A') && int(ret[i]) <= int('Z'))
        {
            ret[i] = char((int(ret[i]) - int('A')) + int('a'));
        }
    }
    return ret;
}
void dfs(int v)
{
    mark[v] = 1;
    for (int u : adjkhor[v])
    {
        if (!mark[u])
        {
            dfs(u);
        }
    }
    topol.pb(v);
}
void dfsg(int v)
{
    num[v] = numi;
    vis[v] = 1;
    if (tr[v] == anmol[numi].F && hlp[v].size() < anmol[numi].S)
    {
        anmol[numi] = {tr[v], hlp[v].size()};
    }
    if (tr[v] < anmol[numi].F)
    {
        anmol[numi] = {tr[v], hlp[v].size()};
    }
    for (int u : adjvor[v])
    {
        if (!vis[u])
        {
            dfsg(u);
        }
    }
}
void ghham()
{
    for (int i = 0; i < topol.size(); i++)
    {
        if (!vis[topol[i]])
        {
            dfsg(topol[i]);
            numi++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] = lower(s[i]);
        hlp.pb(s[i]);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string a, b;
        cin >> a >> b;
        a = lower(a);
        b = lower(b);
        yal.pb({a, b});
        hlp.pb(a);
        hlp.pb(b);
    }
    sort(hlp.begin(), hlp.end());
    hlp.resize(unique(hlp.begin(), hlp.end()) - hlp.begin());
    for (int i = 0; i < hlp.size(); i++)
    {
        tr[i] = cntr(hlp[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int in1 = lower_bound(hlp.begin(), hlp.end(), yal[i].F) - hlp.begin();
        int in2 = lower_bound(hlp.begin(), hlp.end(), yal[i].S) - hlp.begin();
        adjkhor[in1].pb(in2);
        adjvor[in2].pb(in1);
    }
    for (int i = 0; i < hlp.size(); i++)
    {
        if (!mark[i])
        {
            dfs(i);
        }
    }
    reverse(topol.begin(), topol.end());
    memset(anmol, 63, sizeof anmol);
    ghham();
    for (int i = topol.size() - 1; i >= 0; i--)
    {
        for (int u : adjkhor[topol[i]])
        {
            if (anmol[num[u]].F == anmol[num[topol[i]]].F && anmol[num[u]].S < anmol[num[topol[i]]].S)
            {
                anmol[num[topol[i]]] = anmol[num[u]];
            }
            if (anmol[num[u]].F < anmol[num[topol[i]]].F)
            {
                anmol[num[topol[i]]] = anmol[num[u]];
            }
        }
    }
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        int ind = lower_bound(hlp.begin(), hlp.end(), s[i]) - hlp.begin();
        ans1 += anmol[num[ind]].F;
        ans2 += anmol[num[ind]].S;
    }
    cout << ans1 << "  " << ans2;
}
