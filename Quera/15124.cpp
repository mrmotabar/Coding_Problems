#include <bits/stdc++.h>
using namespace std;
int a, b, x;
int main()
{
    cin >> a >> b >> x;
    int ans = 0;
    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j + i <= x; j++)
        {
            if (a % i == 0 && b % j == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
