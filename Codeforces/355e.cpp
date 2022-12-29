#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 1e6 + 10;
int n, k, a[MAX_N], ps[MAX_N], ans, mn = MAX_N, mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        ps[a[i] + 1] += -1;
        ps[max(a[i] - k, 0)] += 1;
    }
    for (int i = 1; i < MAX_N; i++)
    {
        ps[i] += ps[i - 1];
    }
    for (int i = 1; i <= mn; i++)
    {
        int t = 0;
        for (int j = 1; j * i <= mx; j++)
        {
            t += ps[i * j];
        }
        if (t >= n)
        {
            ans = i;
        }
    }
    cout << ans;
}
