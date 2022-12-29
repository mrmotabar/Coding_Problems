#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e6 + 10;
int n, w, a[MAX_N], b[MAX_N], A[MAX_N], B[MAX_N], f[MAX_N], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    if (w == 1)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < w; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        A[i - 1] = a[i] - a[i - 1];
    }
    for (int i = 1; i < w; i++)
    {
        B[i - 1] = b[i] - b[i - 1];
    }
    int cur = 0;
    for (int i = 1; i < w - 1; i++)
    {
        while (cur && B[cur] != B[i])
        {
            cur = f[cur];
        }
        cur += (B[cur] == B[i]);
        f[i + 1] = cur;
    }
    cur = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (cur && B[cur] != A[i])
        {
            cur = f[cur];
        }
        cur += (B[cur] == A[i]);
        if (cur == w - 1)
        {
            ans++;
            cur = f[cur];
        }
    }
    cout << ans;
}
