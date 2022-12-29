#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N = 1e6 + 100;
int n, m, a[MAX_N], sum, step;
int cal(int v)
{
    int ret = (v - a[0]), cur = v;
    for (int i = 1; i < n; i++)
    {
        if (cur >= a[i])
        {
            ret += (cur + 1 - a[i]);
            cur = (cur + 1);
        }
    }
    return ret;
}
int32_t main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    step = m - sum;
    int s = a[0], e = (m / n) + 3;
    while (e - s > 1)
    {
        int mid = (e + s) / 2;
        if (cal(mid) <= step)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    int cur = s, p = 0;
    step -= (s - a[0]);
    a[0] = s;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= cur)
        {
            step -= (cur + 1 - a[i]);
            cur++;
            a[i] = cur;
            p = i;
        }
    }
    while (p + 1 < n && cur + 1 == a[p + 1])
    {
        p++;
        cur++;
    }
    while (step)
    {
        a[p]++;
        step--;
        p--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
