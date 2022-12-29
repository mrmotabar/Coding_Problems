#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
int n, m, c[10][10], t, p[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, ans = 10, pans[9], andes[9];
int rast[10], chap[10], bala[10], paiin[10];
int jad[10][10], par[10];
set<int> st;
void build()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            jad[i][j] = p[(i - 1) * 3 + (j - 1)];
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        par[i] = -1;
    }
}
void buildans()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            jad[i][j] = pans[(i - 1) * 3 + (j - 1)];
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        par[i] = -1;
    }
}
int get_root(int v)
{
    return (par[v] == -1 ? v : par[v] = get_root(par[v]));
}
void mergee(int v, int u)
{
    int pv = get_root(v);
    int pu = get_root(u);
    if (pv == pu)
    {
        return;
    }
    par[pu] = pv;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            if (a == 'X')
            {
                t++;
                c[i][j] = t;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            chap[c[i][j]] = c[i][j - 1];
            rast[c[i][j]] = c[i][j + 1];
            {
                bala[c[i][j]] = c[i - 1][j];
                paiin[c[i][j]] = c[i + 1][j];
            }
        }
    }
    int t[10], tt;
    do
    {
        build();
        tt = 0;
        memset(t, 0, sizeof t);
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (jad[i][j - 1] == chap[jad[i][j]] && jad[i][j - 1] != 0)
                {
                    mergee(jad[i][j], jad[i][j - 1]);
                }
                if (jad[i][j + 1] == rast[jad[i][j]] && jad[i][j + 1] != 0)
                {
                    mergee(jad[i][j], jad[i][j + 1]);
                }
                if (jad[i - 1][j] == bala[jad[i][j]] && jad[i - 1][j] != 0)
                {
                    mergee(jad[i][j], jad[i - 1][j]);
                }
                if (jad[i + 1][j] == paiin[jad[i][j]] && jad[i + 1][j] != 0)
                {
                    mergee(jad[i][j], jad[i + 1][j]);
                }
            }
        }
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                t[get_root(jad[i][j])]++;
                if (t[get_root(jad[i][j])] == 1)
                {
                    tt++;
                }
            }
        }
        if (tt < ans)
        {
            ans = tt;
            for (int i = 0; i < 9; i++)
            {
                pans[i] = p[i];
            }
        }
    } while (next_permutation(p, p + 9));
    buildans();
    st.clear();
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (jad[i][j - 1] == chap[jad[i][j]] && jad[i][j - 1] != 0)
            {
                mergee(jad[i][j], jad[i][j - 1]);
            }
            if (jad[i][j + 1] == rast[jad[i][j]] && jad[i][j + 1] != 0)
            {
                mergee(jad[i][j], jad[i][j + 1]);
            }
            if (jad[i - 1][j] == bala[jad[i][j]] && jad[i - 1][j] != 0)
            {
                mergee(jad[i][j], jad[i - 1][j]);
            }
            if (jad[i + 1][j] == paiin[jad[i][j]] && jad[i + 1][j] != 0)
            {
                mergee(jad[i][j], jad[i + 1][j]);
            }
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            st.insert(get_root(jad[i][j]));
        }
    }
    tt = 0;
    for (int u : st)
    {
        andes[u] = tt;
        tt++;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == 0)
            {
                cout << '.';
            }
            else
            {
                cout << char('A' + andes[get_root(c[i][j])]);
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << char('A' + andes[get_root(jad[i][j])]);
        }
        cout << endl;
    }
}
