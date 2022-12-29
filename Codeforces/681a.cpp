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
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s;
    int x, y;
    while (n--)
    {
        cin >> s >> x >> y;
        if (x >= 2400 && y > x)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
