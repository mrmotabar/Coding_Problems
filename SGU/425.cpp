#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int MAX_N = 1000 + 10;
int n, m, t[MAX_N][MAX_N], col[10 * MAX_N];
vector<int> mosh, adj[10 * MAX_N], adad;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        bool b = 1;
        for (int j = 0; j < m; j++)
        {
            cin >> t[i][j];
            adad.pb(t[i][j]);
            if (i == 0)
            {
                mosh.pb(t[i][j]);
            }
            else if (b && t[i][j] != t[0][j])
            {
                b = 0;
                mosh.pb(t[i][j]);
            }
        }
    }
    sort(mosh.begin(), mosh.end());
    mosh.resize(unique(mosh.begin(), mosh.end()) - mosh.begin());
    sort(adad.begin(), adad.end());
    adad.resize(unique(adad.begin(), adad.end()) - adad.begin());
    for (int i = 1; i < n; i++)
    {
        bool b = 1;
        for (int j = 0; j < m; j++)
        {
            if (b && t[i][j] != t[0][j])
            {
                b = 0;
                int ind1 = lower_bound(mosh.begin(), mosh.end(), t[i][j]) - mosh.begin();
                int ind2 = lower_bound(mosh.begin(), mosh.end(), t[0][j]) - mosh.begin();
                adj[ind1].pb(ind2);
                adj[ind2].pb(ind1);
            }
        }
    }
    memset(col, -1, sizeof col);
    bool ham[50 + 10];
    for (int i = 0; i < mosh.size(); i++)
    {
        memset(ham, 0, sizeof ham);
        for (int u : adj[i])
        {
            if (col[u] != -1)
            {
                ham[col[u]] = 1;
            }
        }
        for (int j = 0; j <= 50; j++)
        {
            if (ham[j] == 0)
            {
                col[i] = j;
                break;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < adad.size(); i++)
    {
        int ind = lower_bound(mosh.begin(), mosh.end(), adad[i]) - mosh.begin();
        if (ind >= mosh.size() || ind < 0 || mosh[ind] != adad[i])
        {
            cout << adad[i] << " -> 0\n";
        }
        else
        {
            cout << adad[i] << " -> " << col[ind] << "\n";
        }
    }
}
