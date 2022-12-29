#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N = 1e6;
bool aval[MAX_N];
int ans, t;
int32_t main()
{
    memset(aval, 1, sizeof aval);
    aval[1] = 0;
    for (int i = 2; i < MAX_N; i++)
    {
        if (aval[i])
        {
            for (int j = i * i; j < MAX_N; j += i)
            {
                aval[j] = 0;
            }
        }
    }
    for (int i = -1000; i <= 1000; i++)
    {
        for (int j = -1000; j <= 1000; j++)
        {
            int ind = 0;
            while (aval[(ind * ind) + (i * ind) + j])
            {
                ind++;
            }
            if (ind > t)
            {
                t = ind;
                ans = i * j;
            }
        }
    }
    cout << ans;
}
