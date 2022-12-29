#include <bits/stdc++.h>
using namespace std;
int c[8] = {1, 2, 5, 10, 20, 50, 100, 200}, dp[200 + 10][8 + 10];
int main()
{
    dp[0][0] = 1;
    for (int i = 0; i <= 200; i++)
    {
        if (i % c[0] == 0)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j < 8; j++)
        {
            if (i >= c[j])
            {
                dp[i][j] = dp[i - c[j]][j] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    cout << dp[200][7] << endl;
}
