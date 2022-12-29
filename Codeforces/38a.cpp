#include <iostream>
#include <cstdio>
using namespace std;
int s[1000000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> s[i];
	}
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for (int i = a - 1; i < b - 1; i++)
	{
		sum += s[i];
	}
	cout << sum;
}
