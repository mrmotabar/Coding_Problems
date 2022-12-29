#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int n;
	long long int sum = 0;
	cin >> n;
	long long int x;
	long long int b = 1, a;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > b)
		{
			b = x;
		}
		sum += x;
	}
	cout << max(((sum - 1) / (n - 1)) + 1, b);
}
