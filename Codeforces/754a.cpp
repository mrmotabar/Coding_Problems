/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define F first
#define S second
int a[1000000];
int sum, s;
bool x = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] != 0)
		{
			x = 0;
		}
		sum += a[i];
	}
	if (x)
	{
		cout << "NO";
		return 0;
	}
	if (sum != 0)
	{
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << " " << n;
		return 0;
	}
	cout << "YES" << endl;
	cout << 2 << endl;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
		if (s != 0 && sum - s != 0)
		{
			cout << 1 << " " << i + 1 << endl;
			cout << i + 2 << " " << n;
			return 0;
		}
	}
}
