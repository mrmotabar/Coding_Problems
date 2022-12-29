#include <bits/stdc++.h>
using namespace std;
int a[2][10000 + 10], sza[2];
int main()
{
    a[0][0] = 1;
    sza[0] = 1;
    a[1][0] = 1;
    sza[1] = 1;
    int ind = 3;
    while (1)
    {
        for (int i = 0; i < max(sza[0], sza[1]); i++)
        {
            a[ind % 2][i] += a[(ind + 1) % 2][i];
            a[ind % 2][i + 1] += a[ind % 2][i] / 10;
            a[ind % 2][i] %= 10;
        }
        sza[ind % 2] = max(sza[0], sza[1]);
        while (a[ind % 2][sza[ind % 2]] > 0)
        {
            a[ind % 2][sza[ind % 2] + 1] = a[ind % 2][sza[ind % 2]] / 10;
            a[ind % 2][sza[ind % 2]] %= 10;
            sza[ind % 2]++;
        }
        if (sza[ind % 2] >= 1000)
        {
            cout << ind;
            return 0;
        }
        /*if(ind == 126){
            for(int i = sza[ind % 2] - 1;i >= 0; i--){
                cout<<a[ind % 2][i];
            }
            cout<<endl;
        }*/
        ind++;
    }
}
