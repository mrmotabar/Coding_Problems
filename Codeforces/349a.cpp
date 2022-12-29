#include <iostream>
#include <cstdio>
using namespace std;
int a[100000 + 10];
int c[3];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 25)
		{
			c[0]++;
		}
		if (a[i] == 50)
		{
			c[1]++;
			c[0]--;
		}
		if (a[i] == 100 && c[1] > 0)
		{
			c[0]--;
			c[1]--;
			c[2]++;
		}
		else if (a[i] == 100 && c[1] == 0)
		{
			c[0] -= 3;
			c[2]++;
		}
		if (c[0] < 0 || c[1] < 0 || c[2] < 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
