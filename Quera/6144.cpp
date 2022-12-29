#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e5 + 10;
int n, l[MAX_N], t = 1, ind[MAX_N], ans;
vector<int> p[MAX_N];
vector<pair<int, pair<int, int>>> so;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
        int ci;
        for (int j = 0; j < l[i]; j++)
        {
            cin >> ci;
            p[i].pb(ci);
            so.pb({ci, {i, j}});
        }
    }
    sort(so.begin(), so.end());
    for (int i = 0; i < so.size(); i++)
    {
        auto u = so[i];
        if (u.S.S < ind[u.S.F])
        {
            continue;
        }
        while (1)
        {
            if (t > p[u.S.F][ind[u.S.F]] || t > u.F)
            {
                cout << ans;
                return 0;
            }
            t++;
            if (ind[u.S.F] == u.S.S)
            {
                ans++;
                ind[u.S.F]++;
                break;
            }
            else
            {
                ans++;
                ind[u.S.F]++;
            }
        }
    }
    cout << ans;
}
