#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a;
    long long t1 = 0, t2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a < 0)
        {
            t2++;
        }
        else
        {
            t1++;
        }
    }
    long long ans = t2 * (t2 + t1 - 1);
    cout << ans << "\n";
}
