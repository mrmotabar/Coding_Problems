#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 500000 + 10, INF = 1e9 + 1;
int q, w, h, tof, tamm;
pair<char, int> quer[MAX_N];
vector<int> com[2];
struct node
{
    int t, ans;
} seg[2][4 * MAX_N];
void upd(int id, int b, int e, int p, int ind)
{
    if (p < b || p >= e)
    {
        return;
    }
    if (e - b == 1)
    {
        seg[ind][id].t = 1;
        seg[ind][id].ans = -1 * com[ind][p];
        return;
    }
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, p, ind);
    upd(id * 2 + 1, mid, e, p, ind);
    seg[ind][id].t = seg[ind][id * 2].t + seg[ind][id * 2 + 1].t;
    if (seg[ind][id * 2].t % 2 == 1)
    {
        seg[ind][id].ans = seg[ind][id * 2].ans - seg[ind][id * 2 + 1].ans;
    }
    else
    {
        seg[ind][id].ans = seg[ind][id * 2].ans + seg[ind][id * 2 + 1].ans;
    }
}
int32_t main()
{
    cin >> w >> h >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> quer[i].F >> quer[i].S;
        if (quer[i].F == 'H')
        {
            com[0].pb(quer[i].S);
        }
        else
        {
            com[1].pb(quer[i].S);
        }
    }
    com[0].pb(0);
    com[0].pb(h);
    com[1].pb(0);
    com[1].pb(w);
    sort(com[0].begin(), com[0].end());
    com[0].resize(unique(com[0].begin(), com[0].end()) - com[0].begin());
    sort(com[1].begin(), com[1].end());
    com[1].resize(unique(com[1].begin(), com[1].end()) - com[1].begin());
    upd(1, 0, com[0].size(), 0, 0);
    upd(1, 0, com[0].size(), com[0].size() - 1, 0);
    upd(1, 0, com[1].size(), 0, 1);
    upd(1, 0, com[1].size(), com[1].size() - 1, 1);
    for (int i = 0; i < q; i++)
    {
        if (quer[i].F == 'H')
        {
            tof++;
            int ind = lower_bound(com[0].begin(), com[0].end(), quer[i].S) - com[0].begin();
            upd(1, 0, com[0].size(), ind, 0);
        }
        else
        {
            tamm++;
            int ind = lower_bound(com[1].begin(), com[1].end(), quer[i].S) - com[1].begin();
            upd(1, 0, com[1].size(), ind, 1);
        }
        int amm = seg[0][1].ans;
        int of = seg[1][1].ans;
        if (tof % 2 == 1)
        {
            amm += h;
        }
        if (tamm % 2 == 1)
        {
            of += w;
        }
        int ans = (of * amm) + ((h - amm) * (w - of));
        ans = max(ans, w * h - ans);
        cout << ans << endl;
    }
}
