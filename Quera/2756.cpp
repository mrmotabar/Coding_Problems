/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int b, c, n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 5)
        {
            b++;
        }
        else
        {
            b++;
            c++;
        }
    }
    cout << 5 << " " << b << " " << -1 * c << endl;
}
