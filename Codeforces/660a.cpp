#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> ar;
int gcd(int x, int y)
{
	int a;
	while (x != 0)
	{
		a = x;
		x = y % x;
		y = a;
	}
	return y;
}
int main()
{
	int n, a;
	cin >> n >> a;
	ar.push_back(a);
	for (int i = 1; i < n; i++)
	{
		int b = a;
		cin >> a;
		if (gcd(b, a) != 1)
		{
			ar.push_back(1);
		}
		ar.push_back(a);
	}
	cout << ar.size() - n << endl;
	for (int i = 0; i < ar.size(); i++)
	{
		cout << ar[i] << " ";
	}
}
