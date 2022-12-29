#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define F first
#define S second
using namespace std;
const int MAX_N = 1e5 + 10;
int n, k, h;
pair<int, pair<int, int>> mvi[MAX_N];
bool ch(ld x, bool b)
{
    int t = 0, ind = 1;
    for (int i = 0; i < n && ind <= k; i++)
    {
        if (((1.0 * ind * h) / (1.0 * mvi[i].S.F)) <= x)
        {
            ind++;
            t++;
            if (b)
            {
                cout << mvi[i].S.S + 1 << " ";
            }
        }
    }
    if (t == k)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> mvi[i].F;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mvi[i].S.F;
        mvi[i].S.S = i;
    }
    sort(mvi, mvi + n);
    ld s = 0, e = 1e9;
    for (int i = 0; i < 100; i++)
    {
        ld mid = (e + s) / 2;
        if (ch(mid, 0))
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
    }
    ch(e, 1);
}
