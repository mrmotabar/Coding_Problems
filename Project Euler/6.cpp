#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum1 += i;
    }
    sum1 = sum1 * sum1;
    for (int i = 1; i <= 100; i++)
    {
        sum2 += i * i;
    }
    cout << sum1 - sum2;
}
