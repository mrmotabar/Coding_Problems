#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0;
    sum += 11;                                           // 1000
    sum += (3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4) * 100;    // ragham chap
    sum += (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) * 10 * 10;    // ragham vasat
    sum += (3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4) * 10 * 9; // ragham rast
    sum += 9 * 7 * 100;                                  // hundred
    sum += 3 * 99 * 9;                                   // and
    sum += (3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8) * 10; // 11 ta 19
    cout << sum;
}
