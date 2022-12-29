#include <bits/stdc++.h>
using namespace std;
int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, now = 3, ans;
int main()
{
    for (int i = 1901; i <= 2000; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (now == 1)
            {
                ans++;
            }
            if (i % 4 == 0 && j == 1)
            {
                now = (((m[j] + 1) % 7) + now) % 7;
            }
            else
            {
                now = ((m[j] % 7) + now) % 7;
            }
        }
    }
    cout << ans;
}
