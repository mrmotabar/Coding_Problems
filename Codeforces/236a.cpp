#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    int t = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                s[j] = '1';
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '1')
        {
            t++;
        }
    }
    if (t % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }
}
