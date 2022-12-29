#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n == 4)
	{
		cout << 4 << endl;
		cout << "3 1 4 2";
	}
	if (n == 3)
	{
		cout << 2 << endl;
		cout << "1 3";
	}
	if (n == 2 || n == 1)
	{
		cout << 1 << endl;
		cout << 1;
	}
	if (n > 4)
	{
		cout << n << endl;
		for (int i = 1; i <= n; i += 2)
		{
			cout << i << " ";
		}
		for (int j = 2; j <= n; j += 2)
		{
			cout << j << " ";
		}
	}
}
