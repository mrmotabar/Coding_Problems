#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    if (n >= 28)
    {
        cout << m << endl;
        return 0;
    }
    int a = (1 << n);
    cout << m % a << endl;
}
