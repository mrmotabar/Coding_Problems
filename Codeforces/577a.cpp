#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    if (x == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (x % i == 0 && x / i <= n)
        {
            ans++;
        }
    }
    if (x <= n)
    {
        ans++;
    }
    cout << ans;
}
