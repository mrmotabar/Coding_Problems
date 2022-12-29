#include <bits/stdc++.h>
using namespace std;
int ans, ans2;
int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        int t = 0;
        for (int a = 1; a <= i; a++)
        {
            for (int b = 1; b <= a; b++)
            {
                int c = i - (a + b);
                if (c * c == a * a + b * b && a + b + c == i)
                {
                    t++;
                }
            }
        }
        if (t > ans)
        {
            ans = t;
            ans2 = i;
        }
    }
    cout << ans2;
}
