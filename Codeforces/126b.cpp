#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 10;
string a, b;
int f[MAX_N];
bool ans;
int main()
{
    cin >> a;
    int cur = 0;
    for (int i = 1; i < a.size(); i++)
    {
        while (cur && a[cur] != a[i])
        {
            cur = f[cur - 1];
        }
        cur += (a[cur] == a[i]);
        f[i] = cur;
    }
    if (f[a.size() - 1] == 0)
    {
        cout << "Just a legend";
        return 0;
    }
    for (int i = 0; i < f[a.size() - 1]; i++)
    {
        b += a[i];
    }
    memset(f, 0, sizeof f);
    cur = 0;
    for (int i = 1; i < b.size(); i++)
    {
        while (cur && b[cur] != b[i])
        {
            cur = f[cur - 1];
        }
        cur += (b[cur] == b[i]);
        f[i] = cur;
    }
    cur = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (cur && b[cur] != a[i])
        {
            cur = f[cur - 1];
        }
        cur += (b[cur] == a[i]);
        if (cur == b.size())
        {
            cur = f[cur - 1];
            if (i >= b.size() && i < a.size() - 1)
            {
                cout << b;
                return 0;
            }
        }
    }
    int t = f[b.size() - 1];
    if (t > 0)
    {
        for (int i = 0; i < t; i++)
        {
            cout << a[i];
        }
    }
    else
    {
        cout << "Just a legend";
    }
}
