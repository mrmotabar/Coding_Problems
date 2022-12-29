#include <iostream>
#include <cstdio>
using namespace std;
int n;
void print(int m)
{
	for (int i = 1; i <= n - m; i++)
	{
		cout << "  ";
	}
	if (m == 0)
	{
		cout << 0 << endl;
		return;
	}
	for (int i = 0; i <= m; i++)
	{
		cout << i << " ";
	}
	for (int i = m - 1; i >= 1; i--)
	{
		cout << i << " ";
	}
	if (m > 0)
	{
		cout << '0';
	}
	cout << endl;
	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		print(i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		print(i);
	}
}
