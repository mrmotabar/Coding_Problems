/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n;
vector<pair<int, pair<int, int>>> a, b;
vector<pair<pair<int, int>, pair<int, int>>> soa;
map<pair<int, int>, pair<int, int>> mpb;
void solva(int ind, int a1, int a2, int a3, int chi)
{
    if (ind == a.size())
    {
        soa.pb({{a1, a2}, {a3, chi}});
        return;
    }
    solva(ind + 1, a1 + a[ind].F, a2, a3 + a[ind].S.S, chi * 3 + 0);
    solva(ind + 1, a1 + a[ind].F, a2 + a[ind].S.F, a3, chi * 3 + 1);
    solva(ind + 1, a1, a2 + a[ind].S.F, a3 + a[ind].S.S, chi * 3 + 2);
}
void solvb(int ind, int a1, int a2, int a3, int chi)
{
    if (ind == b.size())
    {
        if (mpb.count({a2 - a1, a3 - a1}) == 0)
        {
            mpb[{a2 - a1, a3 - a1}] = {a1, chi};
        }
        else
        {
            if (mpb[{a2 - a1, a3 - a1}].F < a1)
            {
                mpb[{a2 - a1, a3 - a1}] = {a1, chi};
            }
        }
        return;
    }
    solvb(ind + 1, a1 + b[ind].F, a2, a3 + b[ind].S.S, chi * 3 + 0);
    solvb(ind + 1, a1 + b[ind].F, a2 + b[ind].S.F, a3, chi * 3 + 1);
    solvb(ind + 1, a1, a2 + b[ind].S.F, a3 + b[ind].S.S, chi * 3 + 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        if (i * 2 < n)
        {
            a.pb({a1, {a2, a3}});
        }
        else
        {
            b.pb({a1, {a2, a3}});
        }
    }
    if (n == 1)
    {
        b.pb({0, {0, 0}});
    }
    bool yaf = false;
    pair<int, pair<int, int>> ans;
    ans.F = -INF;
    solva(0, 0, 0, 0, 1);
    solvb(0, 0, 0, 0, 1);
    for (auto u : soa)
    {
        int f1, f2, f3, mx;
        mx = max(u.F.F, max(u.F.S, u.S.F));
        f1 = mx - u.F.F;
        f2 = mx - u.F.S;
        f3 = mx - u.S.F;
        int a2 = f2 - f1;
        int a3 = f3 - f1;
        if (mpb.count({a2, a3}) > 0)
        {
            // cout<<u.F.F<<" "<<u.F.S<<"  "<<u.S.F<<endl;
            yaf = true;
            if (mpb[{a2, a3}].F + u.F.F > ans.F)
            {
                ans.F = mpb[{a2, a3}].F + u.F.F;
                ans.S.F = u.S.S;
                ans.S.S = mpb[{a2, a3}].S;
            }
        }
    }
    if (yaf == false)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    else
    {
        // cout<<ans.S.F<<"  "<<ans.S.S<<endl;
        vector<pair<char, char>> ana, anb;
        int t = ans.S.F;
        while (t > 0)
        {
            if (t % 3 == 0)
            {
                ana.pb({'L', 'W'});
            }
            else if (t % 3 == 1)
            {
                ana.pb({'L', 'M'});
            }
            else
            {
                ana.pb({'M', 'W'});
            }
            t /= 3;
        }
        t = ans.S.S;
        while (t > 0)
        {
            if (t % 3 == 0)
            {
                anb.pb({'L', 'W'});
            }
            else if (t % 3 == 1)
            {
                anb.pb({'L', 'M'});
            }
            else
            {
                anb.pb({'M', 'W'});
            }
            t /= 3;
        }
        for (int i = ana.size() - 2; i >= 0; i--)
        {
            cout << ana[i].F << ana[i].S << endl;
        }
        for (int i = anb.size() - 2; i >= 0 && n != 1; i--)
        {
            cout << anb[i].F << anb[i].S << endl;
        }
    }
}
