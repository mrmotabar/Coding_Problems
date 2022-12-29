#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAX_N = 2e5 + 10;
int n, m, a[MAX_N], chap[MAX_N], rast[MAX_N], tr, tl;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[now])
        {
            now = i;
        }
        chap[i] = now;
    }
    now = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] > a[now])
        {
            now = i;
        }
        rast[i] = now;
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        if (c == 'R')
        {
            tr++;
        }
        else
        {
            tl++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[chap[i]] <= a[rast[i]])
        {
            cout << min((min(a[i] + tl, a[chap[i]]) + tr), a[rast[i]]) << " ";
        }
        else
        {
            cout << min((min(a[i] + tr, a[rast[i]]) + tl), a[chap[i]]) << " ";
        }
    }
}
