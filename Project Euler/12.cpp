#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll sum = 0;
    for (int i = 1; 1; i++)
    {
        sum += i;
        int t = 1, kom = sum;
        for (int j = 2; j < sqrt(sum); j++)
        {
            int now = 0;
            if (kom % j == 0)
            {
                while (kom % j == 0)
                {
                    now++;
                    kom /= j;
                }
            }
            t *= (now + 1);
        }
        if (t > 500)
        {
            cout << sum;
            return 0;
        }
    }
}
