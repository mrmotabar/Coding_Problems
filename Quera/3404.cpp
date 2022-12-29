/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
double n, m;
int main()
{
	ios::sync_with_stdio(false);
	std::cout << std::setprecision(2) << std::fixed;
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	double a = n / (m * m);
	cout << a << endl;
	if (a < 18.5)
	{
		cout << "Underweight";
	}
	else if (a < 25)
	{
		cout << "Normal";
	}
	else if (a < 30)
	{
		cout << "Overweight";
	}
	else
	{
		cout << "Obese";
	}
}
