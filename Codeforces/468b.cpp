#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 1e6 + 10;
int n, a, b, p[MAX_N], num[MAX_N];
map<int, int> jay;
vector<int> khor[MAX_N], vor[MAX_N], topol;
bool mark[MAX_N];
void dfs(int v)
{
    mark[v] = 1;
    for (int u : khor[v])
    {
        if (!mark[u])
        {
            dfs(u);
        }
    }
    topol.pb(v);
}
void sfd(int v, int nu)
{
    mark[v] = 1;
    num[v] = nu;
    for (int u : vor[v])
    {
        if (!mark[u])
        {
            sfd(u, nu);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        jay[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!jay[a - p[i]])
        {
            khor[2 * i + 1].pb(2 * i);
            vor[2 * i].pb(2 * i + 1);
        }
        else
        {
            khor[2 * i].pb(2 * jay[a - p[i]]);
            vor[2 * jay[a - p[i]]].pb(2 * i);
            khor[2 * i + 1].pb(2 * jay[a - p[i]] + 1);
            vor[2 * jay[a - p[i]] + 1].pb(2 * i + 1);

            khor[2 * jay[a - p[i]]].pb(2 * i);
            vor[2 * i].pb(2 * jay[a - p[i]]);
            khor[2 * jay[a - p[i]] + 1].pb(2 * i + 1);
            vor[2 * i + 1].pb(2 * jay[a - p[i]] + 1);
        }
        if (!jay[b - p[i]])
        {
            khor[2 * i].pb(2 * i + 1);
            vor[2 * i + 1].pb(2 * i);
        }
        else
        {
            khor[2 * i].pb(2 * jay[b - p[i]]);
            vor[2 * jay[b - p[i]]].pb(2 * i);
            khor[2 * i + 1].pb(2 * jay[b - p[i]] + 1);
            vor[2 * jay[b - p[i]] + 1].pb(2 * i + 1);

            khor[2 * jay[b - p[i]]].pb(2 * i);
            vor[2 * i].pb(2 * jay[b - p[i]]);
            khor[2 * jay[b - p[i]] + 1].pb(2 * i + 1);
            vor[2 * i + 1].pb(2 * jay[b - p[i]] + 1);
        }
    }
    for (int i = 2; i <= 2 * n + 1; i++)
    {
        if (!mark[i])
        {
            dfs(i);
        }
    }
    reverse(topol.begin(), topol.end());
    memset(mark, 0, sizeof mark);
    int nu = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (!mark[topol[i]])
        {
            sfd(topol[i], nu);
            nu++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[2 * i] == num[2 * i + 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (num[2 * i] < num[2 * i + 1])
        {
            cout << 0 << " ";
        }
        else
        {
            cout << 1 << " ";
        }
    }
    cout << endl;
}
