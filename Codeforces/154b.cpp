#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e5 + 10;
int n, m, aval[MAX_N], mp[MAX_N];
bool hast[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 2; i < MAX_N; i++)
    {
        if (aval[i] == 0)
        {
            aval[i] = i;
            for (ll j = i * i; j < MAX_N; j += i)
            {
                if (aval[j] == 0)
                {
                    aval[j] = i;
                }
            }
        }
    }
    cin >> n >> m;
    char c;
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> x;
        if (c == '+')
        {
            if (hast[x] == 1)
            {
                cout << "Already on\n";
            }
            else
            {
                bool mishe = 1;
                int y = x;
                while (y > 1)
                {
                    if (mp[aval[y]] > 0)
                    {
                        mishe = 0;
                        cout << "Conflict with " << mp[aval[y]] << "\n";
                        break;
                    }
                    y /= aval[y];
                }
                if (mishe)
                {
                    y = x;
                    while (y > 1)
                    {
                        mp[aval[y]] = x;
                        y /= aval[y];
                    }
                    hast[x] = 1;
                    cout << "Success\n";
                }
            }
        }
        else
        {
            if (hast[x] == 0)
            {
                cout << "Already off\n";
            }
            else
            {
                int y = x;
                while (y > 1)
                {
                    mp[aval[y]] = 0;
                    y /= aval[y];
                }
                hast[x] = 0;
                cout << "Success\n";
            }
        }
    }
}
