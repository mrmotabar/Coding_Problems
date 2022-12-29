#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	string a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int j = 0; j < n; j++)
	{
		if (a[j].size() > 10)
		{
			cout << a[j][0] << a[j].size() - 2 << a[j][a[j].size() - 1];
		}
		else
		{
			cout << a[j];
		}
		cout << endl;
	}
}
