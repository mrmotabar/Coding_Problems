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

string s, p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> p;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = i;
        bool is = 1;
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] != s[(ind + j) % s.size()])
            {
                is = 0;
            }
        }
        if (is)
        {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}
