#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int t = 1;
    while (t < 1000000)
    {
        next_permutation(a, a + 10);
        t++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
}
