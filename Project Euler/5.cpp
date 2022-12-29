#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 1;
    int aval[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (int i = 0; i < 8; i++)
    {
        int x = 1;
        while (1)
        {
            if (x * aval[i] > 20)
            {
                break;
            }
            x *= aval[i];
        }
        ans *= x;
    }
    cout << ans;
}
