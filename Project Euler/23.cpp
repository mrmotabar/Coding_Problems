#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 28123 + 10;
int su[MAX_N], ans;
bool ab[MAX_N];
int main()
{
    for (int i = 1; i < MAX_N; i++)
    {
        for (int j = i + i; j < MAX_N; j += i)
        {
            su[j] += i;
            if (su[j] > j)
            {
                ab[j] = 1;
            }
        }
    }
    for (int i = 1; i < MAX_N; i++)
    {
        bool mish = 0;
        for (int j = 1; j < i; j++)
        {
            if (ab[j] && ab[i - j])
            {
                mish = 1;
            }
        }
        if (!mish)
        {
            ans += i;
        }
    }
    cout << ans;
}
