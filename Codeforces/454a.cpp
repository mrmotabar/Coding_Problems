#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n / 2; i++)
	{
		int k = (i * 2) + 1;
		int y = (n - k) / 2;
		for (int j = 1; j <= y; j++)
		{
			cout << "*";
		}
		for (int j = 1; j <= k; j++)
		{
			cout << "D";
		}
		for (int j = 1; j <= y; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "D";
	}
	cout << endl;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		int k = (i * 2) + 1;
		int y = (n - k) / 2;
		for (int j = 1; j <= y; j++)
		{
			cout << "*";
		}
		for (int j = 1; j <= k; j++)
		{
			cout << "D";
		}
		for (int j = 1; j <= y; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
