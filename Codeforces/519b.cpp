#include <iostream>
#include <cstdio>
using namespace std;
long long n, su1, su2, su3, a;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		su1 += a;
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a;
		su2 += a;
	}
	for (int i = 0; i < n - 2; i++)
	{
		cin >> a;
		su3 += a;
	}
	cout << su1 - su2 << endl
		 << su2 - su3;
}
