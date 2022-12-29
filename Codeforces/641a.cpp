#include <iostream>
#include <cstdio>
using namespace std;
char a[100000];
int b[100000];
bool vis[100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	int p = 0;
	while (p >= 0 && p < n)
	{
		if (vis[p])
		{
			cout << "INFINITE";
			return 0;
		}
		vis[p] = 1;
		if (a[p] == '<')
		{
			p -= b[p];
		}
		else if (a[p] == '>')
		{
			p += b[p];
		}
	}
	cout << "FINITE";
}
