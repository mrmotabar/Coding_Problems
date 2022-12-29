#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int MAX_N = 1e5 + 10;
int n, x;
bool aval[MAX_N], mark[MAX_N];
vector<int> av, gc[MAX_N], ez;
int32_t main()
{
    memset(aval, 1, sizeof aval);
    cin >> n;
    aval[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (aval[i])
        {
            if (i > n / 2)
            {
                x++;
            }
            else
            {
                av.pb(i);
            }
            for (ll j = i * i; j <= n; j += i)
            {
                aval[j] = 0;
            }
        }
    }
    cout << (n - x - 1) / 2 << "\n";
    for (int i = av.size() - 1; i >= 0; i--)
    {
        for (int j = 1; j * av[i] <= n; j++)
        {
            if (!mark[j * av[i]])
            {
                gc[av[i]].pb(av[i] * j);
                mark[j * av[i]] = 1;
            }
        }
    }
    for (int u : av)
    {
        if (gc[u].size() % 2 == 1)
        {
            ez.pb(gc[u][1]);
            cout << gc[u][0] << " " << gc[u][2] << "\n";
            for (int i = 3; i < gc[u].size(); i += 2)
            {
                cout << gc[u][i] << " " << gc[u][i + 1] << "\n";
            }
        }
        else
        {
            for (int i = 0; i < gc[u].size(); i += 2)
            {
                cout << gc[u][i] << " " << gc[u][i + 1] << "\n";
            }
        }
    }
    if (ez.size() % 2 == 1)
    {
        ez.pop_back();
    }
    for (int i = 0; i < ez.size(); i += 2)
    {
        cout << ez[i] << " " << ez[i + 1] << "\n";
    }
}
