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
string orgi, fake;
int mosor, manor, mosfa, manfa, soal, ente[10 + 5][10 + 5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> orgi >> fake;
    ente[0][0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                ente[i][j] = 1;
            }
            else
            {
                ente[i][j] = ente[i - 1][j] + ente[i - 1][j - 1];
            }
        }
    }
    for (int i = 0; i < orgi.size(); i++)
    {
        if (orgi[i] == '+')
        {
            mosor++;
        }
        else
        {
            manor++;
        }
        if (fake[i] == '+')
        {
            mosfa++;
        }
        else if (fake[i] == '-')
        {
            manfa++;
        }
        else
        {
            soal++;
        }
    }
    if (mosfa > mosor || manfa > manor)
    {
        cout << fixed << setprecision(11) << double(0) << endl;
        return 0;
    }
    double ans = 0;
    ans = (ente[soal][mosor - mosfa]) / (pow(2, soal));
    cout << fixed << setprecision(11) << ans << endl;
}
