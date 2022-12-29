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

string s[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < s[0].size(); i += 5)
    {
        if (s[0][i] == 'o')
        {
            cout << 'A';
        }
        else if (s[2][i] == 'o')
        {
            cout << 'T';
        }
        else if (s[1][i] == 'o')
        {
            cout << 'X';
        }
        else if (s[0][i + 1] == 'o')
        {
            cout << 'N';
        }
        else
        {
            cout << 'M';
        }
    }
}
