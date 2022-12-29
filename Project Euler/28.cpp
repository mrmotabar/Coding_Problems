#include <bits/stdc++.h>
using namespace std;
int n = 1001, a[5000][5000], sum = 0;
int main()
{
    a[2500 + 0][2500 + 0] = 1;
    a[2500 + 0][2500 + 1] = 2;
    int x = 1, y = 1, jah = 0;
    for (int i = 3; i <= n * n; i++)
    {
        a[2500 + x][2500 + y] = i;
        if (jah == 0)
        {
            if (a[2500 + x - 1][2500 + y] > 0)
            {
                y--;
            }
            else
            {
                x--;
                jah = 1;
            }
        }
        else if (jah == 1)
        {
            if (a[2500 + x][2500 + y + 1] > 0)
            {
                x--;
            }
            else
            {
                y++;
                jah = 2;
            }
        }
        else if (jah == 2)
        {
            if (a[2500 + x + 1][2500 + y] > 0)
            {
                y++;
            }
            else
            {
                x++;
                jah = 3;
            }
        }
        else if (jah == 3)
        {
            if (a[2500 + x][2500 + y - 1] > 0)
            {
                x++;
            }
            else
            {
                y--;
                jah = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += a[2500 - ((n - 1) / 2) + i][2500 - ((n - 1) / 2) + i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += a[2500 + ((n - 1) / 2) - i][2500 - ((n - 1) / 2) + i];
    }
    cout << sum - 1;
}
