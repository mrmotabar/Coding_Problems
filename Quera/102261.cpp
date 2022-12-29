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

int q, l, r;
vector<int> a2;

void prep()
{
    for (int i = 1; i * i <= INF * 2; i++)
    {
        a2.pb(i * i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prep();

    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        int ind1 = lower_bound(a2.begin(), a2.end(), r) - a2.begin();
        int ind2 = lower_bound(a2.begin(), a2.end(), l) - a2.begin();
        if (ind1 == ind2 && a2[ind2] != r)
        {
            cout << 0 << endl;
        }
        else if (a2[ind1] > r)
        {
            ind1--;
            cout << ind1 - ind2 + 1 << endl;
        }
        else
        {
            cout << ind1 - ind2 + 1 << endl;
        }
    }
}
