/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
int n, kha[100 + 100][100 + 100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	kha[1][1] = 1;
	kha[2][1] = 1;
	kha[2][2] = 1;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			kha[i][j] = kha[i - 1][j - 1] + kha[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << kha[i][j] << " ";
		}
		cout << endl;
	}
}
