#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 1e3;
int n, s, a, m, num[MAX_N];
vector<int> khor[MAX_N], vor[MAX_N], topol;
bool mark[MAX_N];
void add_close(int x, int y)
{
    khor[x ^ 1].pb(y);
    vor[y].pb(x ^ 1);
    if (x != y)
    {
        khor[y ^ 1].pb(x);
        vor[x].pb(y ^ 1);
    }
}
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
void sfd(int v, int c)
{
    mark[v] = 1;
    num[v] = c;
    for (int u : vor[v])
    {
        if (!mark[u])
        {
            sfd(u, c);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> s >> a >> m;
        for (int i = 0; i < 2 * (s + a); i++)
        {
            khor[i].clear();
            vor[i].clear();
        }
        topol.clear();
        memset(mark, 0, sizeof mark);
        memset(num, 0, sizeof num);
        int s1, a1, s2, a2;
        for (int i = 0; i < m; i++)
        {
            cin >> s1 >> a1 >> s2 >> a2;
            s1--, a1--, s2--, a2--;
            a1 += s;
            a2 += s;
            s1 *= 2, s2 *= 2, a1 *= 2, a2 *= 2;
            s1 ^= (a2 < a1);
            s2 ^= (a2 < a1);
            a1 ^= (s2 < s1);
            a2 ^= (s2 < s1);
            if (s1 == s2)
            {
                add_close(s1, s1);
            }
            else if (a1 == a2)
            {
                add_close(a1, a1);
            }
            else
            {
                add_close(s1, s2);
                add_close(a1, a2);
                add_close(s1, a1);
                add_close(s2, a2);
            }
        }
        for (int i = 0; i < 2 * (s + a); i++)
        {
            if (!mark[i])
            {
                dfs(i);
            }
        }
        reverse(topol.begin(), topol.end());
        memset(mark, 0, sizeof mark);
        int nu = 0;
        for (int i = 0; i < topol.size(); i++)
        {
            if (!mark[topol[i]])
            {
                sfd(topol[i], nu);
                nu++;
            }
        }
        bool hast = true;
        for (int i = 0; i < s + a; i++)
        {
            if (num[2 * i] == num[2 * i + 1])
            {
                hast = false;
                break;
            }
        }
        if (hast)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
