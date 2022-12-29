#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e6 + 10;
int n, k, c[MAX_N], tam;
vector<pair<int, int>> taj;
bool amel[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int x = k;
    for (int i = 2; i <= k; i++)
    {
        if (x % i == 0)
        {
            amel[i] = 1;
            tam++;
            taj.pb({i, 0});
            while (x % i == 0)
            {
                x /= i;
                taj[taj.size() - 1].S++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto j : taj)
        {
            int t = 0;
            if (amel[j.F])
            {
                while (c[i] % j.F == 0)
                {
                    c[i] /= j.F;
                    t++;
                }
                if (t >= j.S)
                {
                    amel[j.F] = 0;
                    tam--;
                }
            }
        }
    }
    if (!tam)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
