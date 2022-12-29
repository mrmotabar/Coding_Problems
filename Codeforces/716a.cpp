#include <cstdio>
#include <iostream>
using namespace std;
int t[1000000];
int main()
{
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	int x = 0;
	for (int i = 1; i < n; i++)
	{
		if (t[i] - t[i - 1] > c)
		{
			x = 0;
		}
		else
		{
			x++;
		}
	}
	cout << x + 1;
}
