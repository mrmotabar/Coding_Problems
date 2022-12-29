#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a1[100000 + 10], b1[100000 + 10];
int main()
{
	int a, b, k, m;
	cin >> a >> b >> k >> m;
	for (int i = 0; i < a; i++)
	{
		cin >> a1[i];
	}
	for (int i = 0; i < b; i++)
	{
		cin >> b1[i];
	}
	sort(a1, a1 + a);
	sort(b1, b1 + b);
	if (a1[k - 1] < b1[b - m])
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
