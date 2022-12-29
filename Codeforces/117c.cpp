/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 5000 + 2, INF = 1e9;
int n;
bitset<MAX_N> vor[MAX_N], khor[MAX_N], an, orr[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        for (int j = 0; j < n; j++)
        {
            khor[i][j] = c[j] - '0';
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = khor[i]._Find_first(); j < khor[i].size() && j < i; j = khor[i]._Find_next(j))
        {
            orr[i] |= khor[j];
        }
        vor[i] = ~khor[i];
        vor[i][i] = 0;
        an = vor[i] & orr[i];
        if (an.any())
        {
            int ind = an._Find_first();
            vor[ind] = ~khor[ind];
            vor[ind][ind] = 0;
            orr[i] = vor[ind] & khor[i];
            cout << i + 1 << " " << orr[i]._Find_first() + 1 << " " << ind + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}
