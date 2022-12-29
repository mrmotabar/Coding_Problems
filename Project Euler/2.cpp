#include <bits/stdc++.h>
using namespace std;
int f[1000];
int main()
{
    int sum = 0, t = 2;
    f[0] = 1;
    f[1] = 1;
    while (1)
    {
        f[t] = f[t - 1] + f[t - 2];
        if (f[t] >= 4000000)
        {
            break;
        }
        if (f[t] % 2 == 0)
        {
            sum += f[t];
        }
        t++;
    }
    cout << sum;
}
