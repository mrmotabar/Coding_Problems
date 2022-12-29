#include <bits/stdc++.h>
using namespace std;
string s[500000 + 10];
long long ans;
int score(string x)
{
    int ret = 0;
    for (int i = 0; i < x.size(); i++)
    {
        ret += int(x[i]) - int('A') + 1;
    }
    return ret;
}
int main()
{
    freopen("names.txt", "r", stdin);
    string a, b;
    cin >> a;
    int ind = 0;
    int g = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '"')
        {
            g++;
        }
        else
        {
            b += a[i];
        }
        if (g == 2)
        {
            s[ind] = b;
            b.clear();
            ind++;
            g = 0;
            i++;
        }
    }
    sort(s, s + ind);
    for (int i = 0; i < ind; i++)
    {
        ans += score(s[i]) * (i + 1);
    }
    cout << ans;
}
