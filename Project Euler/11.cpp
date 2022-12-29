#include <bits/stdc++.h>
using namespace std;
int a[20 + 10][20 + 10], ans = 0;
int main()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            ans = max(ans, a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3]);
            ans = max(ans, a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3]);
            ans = max(ans, a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j]);
            if (j >= 3)
                ans = max(ans, a[i][j] * a[i + 1][j - 1] * a[i + 2][j - 2] * a[i + 3][j - 3]);
        }
    }
    cout << ans;
}
