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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w, y, mx;
    cin >> y >> w;
    mx = max(y, w);
    int a = 6 - mx + 1;
    if (a == 0)
    {
        cout << "0/1" << endl;
    }
    else if (a == 1)
    {
        cout << "1/6" << endl;
    }
    else if (a == 2)
    {
        cout << "1/3" << endl;
    }
    else if (a == 3)
    {
        cout << "1/2" << endl;
    }
    else if (a == 4)
    {
        cout << "2/3" << endl;
    }
    else if (a == 5)
    {
        cout << "5/6" << endl;
    }
    else
    {
        cout << "1/1" << endl;
    }
}
