#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_N = 1e6 + 10;
int n, q, lh, rh, seg[4 * MAX_N], h[MAX_N];
bool isrev;
void build(int id, int b, int e)
{
    seg[id] = e - b;
    if (e - b == 1)
    {
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
}
void upd(int id, int b, int e, int p, int val)
{
    if (p < b || p >= e)
    {
        return;
    }
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
    if (b >= r || l >= e)
    {
        return 0;
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    int mid = (b + e) / 2;
    return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    build(1, 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        h[i] = 1;
    }
    lh = 1;
    rh = n + 1;
    while (q--)
    {
        int noe, l, r;
        cin >> noe;
        if (noe == 1)
        {
            cin >> l;
            if (l > (rh - lh) / 2)
            {
                isrev ^= 1;
                l = (rh - lh) - l;
            }
            if (!isrev)
            {
                for (int i = lh; i < lh + l; i++)
                {
                    h[2 * lh + 2 * l - i - 1] += h[i];
                    upd(1, 1, n + 1, 2 * lh + 2 * l - i - 1, h[i]);
                }
                lh += l;
            }
            else
            {
                for (int i = rh - l; i < rh; i++)
                {
                    h[2 * rh - 2 * l - i - 1] += h[i];
                    upd(1, 1, n + 1, 2 * rh - 2 * l - i - 1, h[i]);
                }
                rh -= l;
            }
            /*cout<<lh<<" "<<rh<<" "<<isrev<<"\n";
            for(int i=1;i<=n;i++){
                cout<<h[i]<<" ";
            }
            cout<<"\n";*/
        }
        else
        {
            cin >> l >> r;
            if (!isrev)
            {
                cout << get(1, 1, n + 1, lh + l, lh + r) << "\n";
            }
            else
            {
                cout << get(1, 1, n + 1, rh - r, rh - l) << "\n";
            }
        }
    }
}
