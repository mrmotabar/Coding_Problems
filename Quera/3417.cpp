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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        bool boo = 0;
        for (int i = x; i >= x - 100 && i >= 0; i--)
        {
            int sum = 0;
            int a = i;
            while (a > 0)
            {
                sum += a % 10;
                a /= 10;
            }
            if (sum + i == x)
            {
                cout << "Yes" << endl;
                boo = 1;
                break;
            }
        }
        if (!boo)
        {
            cout << "No" << endl;
        }
    }
}
