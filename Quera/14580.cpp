#include <bits/stdc++.h>
using namespace std;
int n, k, x;
string s[1000];
int main()
{
    cin >> n >> x >> k;
    x--;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cout << s[(x + k) % n] << endl;
}
