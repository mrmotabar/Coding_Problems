#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j + i < 1000; j++)
        {
            if (j > (1000 - j - i))
            {
                if (i * i + (1000 - j - i) * (1000 - j - i) == j * j)
                {
                    cout << i * j * (1000 - j - i);
                    return 0;
                }
            }
            else
            {
                if (i * i + j * j == (1000 - i - j) * (1000 - i - j))
                {
                    cout << i * j * (1000 - j - i);
                    return 0;
                }
            }
        }
    }
}
