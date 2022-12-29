/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, ans;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "Tetrahedron")
            ans += 4;
        if (s == "Cube")
            ans += 6;
        if (s == "Octahedron")
            ans += 8;
        if (s == "Dodecahedron")
            ans += 12;
        if (s == "Icosahedron")
            ans += 20;
    }
    cout << ans << endl;
}
