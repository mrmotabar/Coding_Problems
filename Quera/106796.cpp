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

int n, k;
string s;

void ramz()
{
    string temp = s[n - 1] + s.substr(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 'z')
        {
            temp[i] = 'a';
        }
        else
        {
            temp[i] = char(int(temp[i]) + 1);
        }
    }
    s = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;
    while (k--)
    {
        ramz();
    }
    cout << s;
}
