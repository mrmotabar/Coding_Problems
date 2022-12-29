#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sum = sum / (n / 2);
	for (int i = 0; i < n; i++)
	{
		if (b[i] == 0)
		{
			cout << i + 1 << " ";
			for (int j = 0; j < n; j++)
			{
				if (b[j] == 0 && a[j] + a[i] == sum && i != j)
				{
					b[j] = 1;
					b[i] = 1;
					cout << j + 1 << endl;
					break;
				}
			}
		}
	}
}
