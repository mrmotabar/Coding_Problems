#include <iostream>
#include <cstdio>
using namespace std;
int a[100];
int main()
{
	int n;
	cin >> n;
	int p, q;
	cin >> p;
	int x;
	for (int i = 0; i < p; i++)
	{
		cin >> x;
		a[x - 1]++;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> x;
		a[x - 1]++;
	}
	for (int i = (n - 1); i >= 0; i--)
	{
		if (a[i] == 0)
		{
			cout << "Oh, my keyboard!" << endl;
			return 0;
		}
	}
	cout << "I become the guy.";
}
