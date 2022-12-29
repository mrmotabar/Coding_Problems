/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
string a, b, c, z;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	if (a.size() < c.size())
	{
		swap(a, c);
	}
	if (b == "+")
	{
		for (int i = 0; i < (a.size() - c.size()); i++)
		{
			z += '0';
		}
		z += c;
		for (int i = 0; i < a.size(); i++)
		{
			cout << (a[i] - '0') + (z[i] - '0');
		}
	}
	else
	{
		cout << 1;
		for (int i = 0; i < a.size() + c.size() - 2; i++)
		{
			cout << 0;
		}
	}
}
