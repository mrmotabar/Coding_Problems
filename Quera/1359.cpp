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
string a, b;

bool solvelr(int inda, int indb)
{
    if (indb >= b.size())
    {
        return 1;
    }
    if (inda >= a.size() && indb < b.size())
    {
        return 0;
    }
    for (int i = inda; i < a.size(); i++)
    {
        if (a[i] == b[indb])
        {
            if (solvelr(i + 1, indb + 1))
            {
                return 1;
            }
        }
    }
    return 0;
}

bool solverl(int inda, int indb)
{
    if (indb >= b.size())
    {
        return 1;
    }
    if (inda < 0 && indb < b.size())
    {
        return 0;
    }
    for (int i = inda; i >= 0; i--)
    {
        if (a[i] == b[indb])
        {
            if (solverl(i - 1, indb + 1))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (solverl(a.size() - 1, 0) || solvelr(0, 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
