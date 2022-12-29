#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin >> n;
    long long mid = n / 2;
    long long sum = (mid * (mid + 1));
    if (n % 2 == 0)
    {
        sum -= mid;
    }
    cout << fixed << setprecision(7) << double((sum * 1.0) / ((n + 1) * 1.0)) << endl;
}
