#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    int b = a[i];
    int j = i - 1;
    while (a[j] > b && j >= 0)
    {
      a[j + 1] = a[j--];
      a[j + 1] = b;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}
