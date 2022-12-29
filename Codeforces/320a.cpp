#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '1' && a[i + 1] == '4' && a[i + 2] == '4')
        {
            i += 2;
        }
        else if (a[i] == '1' && a[i + 1] == '4')
        {
            i++;
        }
        else if (a[i] == '1')
        {
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
