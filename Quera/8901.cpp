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
map<char, int> h;
char a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a;
    h[a] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        swap(h[a], h[b]);
    }
    if (h['M'] == 1)
        cout << "M" << endl;
    else if (h['R'] == 1)
        cout << "R" << endl;
    else
        cout << "L" << endl;
}
