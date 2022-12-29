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

int x1, x2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x1 >> x2;
    if (x1 == x2)
    {
        cout << "Saal Noo Mobarak!";
    }
    else if (x1 < x2)
    {
        if (x2 - x1 == 1)
        {
            cout << "R";
        }
        else
        {
            cout << "RR";
        }
    }
    else
    {
        if (x1 - x2 == 1)
        {
            cout << "L";
        }
        else
        {
            cout << "LL";
        }
    }
}
