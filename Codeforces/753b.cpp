/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int a[5 + 2], ind = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i <= 9; i++)
	{
		int x, y;
		for (int j = 0; j < 4; j++)
		{
			cout << i;
		}
		cout << endl;
		cin >> x >> y;
		while (x--)
		{
			a[ind] = i;
			ind++;
		}
	}
	do
	{
		int x, y;
		for (int i = 0; i < 4; i++)
		{
			cout << a[i];
		}
		cout << endl;
		cin >> x >> y;
		if (x == 4)
		{
			break;
		}
	} while (next_permutation(a, a + 4));
}
