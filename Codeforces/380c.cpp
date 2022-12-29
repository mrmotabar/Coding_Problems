/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
string s;
int q;
struct node
{
    int rast, chap, ans;
} seg[4 * MAX_N];
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        if (s[b] == '(')
        {
            seg[id].rast = 1;
        }
        else
        {
            seg[id].chap = 1;
        }
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id].ans = seg[id * 2].ans + seg[id * 2 + 1].ans + min(seg[id * 2].rast, seg[id * 2 + 1].chap);
    seg[id].rast = seg[id * 2 + 1].rast;
    seg[id].chap = seg[id * 2].chap;
    seg[id].chap += max(0, seg[id * 2 + 1].chap - seg[id * 2].rast);
    seg[id].rast += max(0, seg[id * 2].rast - seg[id * 2 + 1].chap);
}
node get(int id, int b, int e, int l, int r)
{
    if (l >= e || r <= b)
        return {0, 0, 0};
    if (l <= b && e <= r)
        return seg[id];
    int mid = (e + b) / 2;
    node z = get(id * 2, b, mid, l, r);
    node x = get(id * 2 + 1, mid, e, l, r);
    int ras = x.rast;
    int cha = z.chap;
    int an = min(z.rast, x.chap) + x.ans + z.ans;
    cha += max(x.chap - z.rast, 0);
    ras += max(z.rast - x.chap, 0);
    return {ras, cha, an};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    s = "0" + s;
    build(1, 1, s.size());
    // cout<<seg[1].ans;
    // return 0;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        node ans = get(1, 1, s.size(), a, b + 1);
        cout << 2 * ans.ans << endl;
    }
}
