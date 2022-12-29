#include <iostream>
#include <cstdio>
using namespace std;
string a[200];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		getline(cin, a[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (a[i] != "1")
		{
			for (int j = 0; j <= n; j++)
			{
				if (a[j] == a[i] && i != j)
				{
					a[j] = "1";
					ans++;
				}
			}
			a[i] = "1";
		}
	}
	cout << n - ans;
}
