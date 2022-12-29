#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll en[50][50];
int main()
{
    en[0][0] = 1;
    for (int i = 1; i <= 40; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            en[i][j] = en[i - 1][j] + en[i - 1][j - 1];
        }
    }
    cout << en[40][20];
}
