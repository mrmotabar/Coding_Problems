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
void fsho(string s)
{
    int ind = 0;
    while (ind < s.size())
    {
        int cnt = 0, b = 0;
        for (int i = ind + 1; s[i] == s[ind] && i < s.size(); i++)
        {
            cnt++;
            b++;
        }
        if (cnt > 0)
        {
            cout << s[ind] << cnt + 1;
        }
        else
        {
            cout << s[ind];
        }
        ind += b + 1;
    }
    cout << endl;
}
void gos(string s)
{
    string ret;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (s[i + 1] >= '1' && s[i + 1] <= '9')
        {
            int cnt = 0;
            int j;
            for (j = i + 1; s[j] >= '0' && s[j] <= '9'; j++)
            {
                cnt *= 10;
                cnt += s[j] - '0';
            }
            while (cnt--)
            {
                cout << c;
            }
            i = j - 1;
        }
        else
        {
            cout << c;
        }
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, noe;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> noe >> s;
        if (noe == 1)
        {
            fsho(s);
        }
        else
        {
            gos(s);
        }
    }
}
