#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 2e3 + 10;
int n, num[MAX_N];
pair<string, string> s[MAX_N];
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b;
        c = a[0];
        c += a[1];
        s[i].F = c;
        s[i].S = c;
        s[i].F += a[2];
        s[i].S += b[0];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].F == s[j].F)
            {
                khor[2 * i + 1].pb(2 * j);
                vor[2 * j].pb(2 * i + 1);
                khor[2 * j + 1].pb(2 * i);
                vor[2 * i].pb(2 * j + 1);

                khor[2 * i + 1].pb(2 * i);
                vor[2 * i].pb(2 * i + 1);
                khor[2 * j + 1].pb(2 * j);
                vor[2 * j].pb(2 * j + 1);
            }
            if (s[i].F == s[j].S)
            {
                khor[2 * i + 1].pb(2 * j + 1);
                vor[2 * j + 1].pb(2 * i + 1);
                khor[2 * j].pb(2 * i);
                vor[2 * i].pb(2 * j);
            }
            if (s[i].S == s[j].F)
            {
                khor[2 * i].pb(2 * j);
                vor[2 * j].pb(2 * i);
                khor[2 * j + 1].pb(2 * i + 1);
                vor[2 * i + 1].pb(2 * j + 1);
            }
            if (s[i].S == s[j].S)
            {
                khor[2 * i].pb(2 * j + 1);
                vor[2 * j + 1].pb(2 * i);
                khor[2 * j].pb(2 * i + 1);
                vor[2 * i + 1].pb(2 * j);
            }
        }
    }
    for (int i = 0; i < 2 * n; i++)
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
    for (int i = 0; i < n; i++)
    {
        if (num[2 * i] == num[2 * i + 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        if (num[2 * i] < num[2 * i + 1])
        {
            cout << s[i].F << endl;
        }
        else
        {
            cout << s[i].S << endl;
        }
    }
}
