#include <bits/stdc++.h>
using namespace std;

int n, k, a[100 + 10], sum;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << n - ceil(sum * 1.0 / k) << endl;
}