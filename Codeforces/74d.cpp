/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int MAX_N = 1e6 + 10, INF = 1e9;
int n, q;
int seg[4 * MAX_N];
vector<pair<int, pii>> que;
vector<int> arr;
map<int, int> mp;
set<pii> lrst, bazst;
void voroodi()
{
    cin >> n >> q;
    lrst.insert({0, n + 1});
    bazst.insert({n, 1});
    ll a, b, c;
    while (q--)
    {
        cin >> a;
        if (a == 0)
        {
            cin >> b >> c;
            que.pb({0, {b, c}});
            arr.pb(b);
            arr.pb(c);
        }
        else
        {
            if (mp[a] == 0)
            {
                pii x = *bazst.rbegin();
                bazst.erase(x);
                bazst.insert({x.F / 2, x.S});
                bazst.insert({x.F / 2 - (1 - x.F % 2), x.F / 2 + x.S + 1});
                if (x.F == 1)
                    bazst.insert({0, x.S - 1});
                if (x.F == 2)
                    bazst.insert({0, x.S});

                auto w = (lrst.lower_bound({x.F / 2 + x.S, 0}));
                w--;
                pii y = *w;
                lrst.erase(y);
                lrst.insert({y.F, x.F / 2 + x.S});
                lrst.insert({x.F / 2 + x.S, y.S});

                arr.pb(x.F / 2 + x.S);
                que.pb({x.F / 2 + x.S, {1, 0}});
                mp[a] = x.F / 2 + x.S;
            }
            else
            {
                auto g = &mp[a];
                auto x = lrst.lower_bound({*g, 0});
                pii y = *x;
                x--;
                pii w = *x;
                bazst.erase({y.S - y.F - 1, y.F + 1});
                bazst.erase({w.S - w.F - 1, w.F + 1});
                bazst.insert({y.S - w.F - 1, w.F + 1});

                lrst.erase(y);
                lrst.erase(w);
                lrst.insert({w.F, y.S});

                que.pb({*g, {-1, 0}});
                *g = 0;
            }
        }
    }
}
void upd(int id, int b, int e, int p, int val)
{
    if (p >= e || p < b)
        return;
    if (e - b == 1)
    {
        seg[id] += val;
        return;
    }
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, p, val);
    upd(id * 2 + 1, mid, e, p, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int b, int e, int l, int r)
{
    if (l >= e || b >= r)
        return 0;
    if (l <= b && e <= r)
        return seg[id];
    int mid = (e + b) / 2;
    return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    arr.pb(0);
    voroodi();
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    for (auto i : que)
    {
        if (i.F == 0)
        {
            int s = lower_bound(arr.begin(), arr.end(), i.S.F) - arr.begin();
            int e = lower_bound(arr.begin(), arr.end(), i.S.S) - arr.begin();
            cout << get(1, 1, arr.size(), s, e + 1) << endl;
        }
        else
        {
            int p = lower_bound(arr.begin(), arr.end(), i.F) - arr.begin();
            upd(1, 1, arr.size(), p, i.S.F);
        }
    }
}
