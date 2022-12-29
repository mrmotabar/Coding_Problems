/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 2e5 + 10, INF = 1e9, MAX_L = 20;
ll n, a[MAX_N], b[MAX_N];
ll dpa[MAX_N][MAX_L], dpb[MAX_N][MAX_L];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    memset(dpa, -63, sizeof dpa);
    memset(dpb, 63, sizeof dpb);
    for (int i = 1; i <= n; i++)
    {
        dpa[i][0] = a[i];
        dpb[i][0] = b[i];
    }
    for (int i = 1; i < MAX_L; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = j + (1 << (i - 1));
            if (x > n)
            {
                dpa[j][i] = dpa[j][i - 1];
                dpb[j][i] = dpb[j][i - 1];
            }
            else
            {
                dpa[j][i] = max(dpa[j][i - 1], dpa[x][i - 1]);
                dpb[j][i] = min(dpb[j][i - 1], dpb[x][i - 1]);
            }
        }
    }
    /* for(int i=1;i<=n;i++){
         for(int j=0;j<MAX_L;j++){
             cout<<dpa[i][j]<<"  ";
         }
         cout<<endl;
     }
     return 0;*/
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int ind1 = i;
        ll mi = INF, ma = -INF;
        for (int j = MAX_L - 1; j >= 0; j--)
        {
            if (ind1 + (1 << j) <= n + 1 && min(mi, dpb[ind1][j]) - max(ma, dpa[ind1][j]) > 0)
            {
                ma = max(ma, dpa[ind1][j]);
                mi = min(mi, dpb[ind1][j]);
                ind1 += (1 << j);
            }
        }
        int ind2 = ind1;
        for (int j = MAX_L - 1; j >= 0; j--)
        {
            if (ind2 + (1 << j) <= n + 1 && min(mi, dpb[ind2][j]) - max(ma, dpa[ind2][j]) == 0)
            {
                ma = max(ma, dpa[ind2][j]);
                mi = min(mi, dpb[ind2][j]);
                ind2 += (1 << j);
            }
        }
        // cout<<i<<"   "<<ind2<<"   "<<ind1<<endl;
        ans += ind2 - ind1;
    }
    cout << ans;
}
