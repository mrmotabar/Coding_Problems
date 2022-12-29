#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n / 2 * (i - 1) + 1; j < n / 2 * (i - 1) + n / 2 + 1; j++)
		{
			cout << j << " ";
		}
		for (int j = n * n - (n / 2 * i) + 1; j < n * n - (n / 2 * i) + n / 2 + 1; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
