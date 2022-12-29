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

    int n, temp;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        if (temp > 3 || temp == 1)
        {
            cout << "*" << endl;
        }
        else if (temp == 2)
        {
            cout << "**" << endl;
        }
        else
        {
            cout << "***" << endl;
        }
    }
}
