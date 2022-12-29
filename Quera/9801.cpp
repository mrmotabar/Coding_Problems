#include <bits/stdc++.h>
using namespace std;
const int MAX_K = 50 + 10, MAX_N = 2e5 + 10;
int n, k, t[MAX_K][MAX_K], pallet[MAX_N], q;
int seg[4 * MAX_N][MAX_K];
void shift(int id)
{
    int kom[MAX_K];
    for (int i = 1; i <= k; i++)
    {
        kom[i] = seg[id][seg[id * 2][i]];
    }
    for (int i = 1; i <= k; i++)
    {
        seg[id * 2][i] = kom[i];
    }
    for (int i = 1; i <= k; i++)
    {
        kom[i] = seg[id][seg[id * 2 + 1][i]];
    }
    for (int i = 1; i <= k; i++)
    {
        seg[id * 2 + 1][i] = kom[i];
    }
    for (int i = 1; i <= k; i++)
    {
        seg[id][i] = i;
    }
}
void upd(int id, int b, int e, int l, int r, int c)
{
    if (l >= e || b >= r)
    {
        return;
    }
    if (l <= b && e <= r)
    {
        for (int i = 1; i <= k; i++)
        {
            seg[id][i] = t[seg[id][i]][c];
        }
        return;
    }
    int mid = (b + e) / 2;
    shift(id);
    upd(id * 2, b, mid, l, r, c);
    upd(id * 2 + 1, mid, e, l, r, c);
}
int get(int id, int b, int e, int l)
{
    if (e - b == 1)
    {
        return seg[id][pallet[l]];
    }
    int mid = (b + e) / 2;
    shift(id);
    if (l < mid)
    {
        return get(id * 2, b, mid, l);
    }
    else
    {
        return get(id * 2 + 1, mid, e, l);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> t[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pallet[i];
    }
    for (int i = 1; i < 4 * n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            seg[i][j] = j;
        }
    }
    cin >> q;
    while (q--)
    {
        char noe;
        int l, r, c;
        cin >> noe;
        if (noe == '#')
        {
            cin >> l >> r >> c;
            upd(1, 1, n + 1, l, r + 1, c);
        }
        else
        {
            cin >> l;
            cout << get(1, 1, n + 1, l) << "\n";
        }
    }
}
