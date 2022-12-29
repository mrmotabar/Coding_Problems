/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5, INF = 1e9;
double a, b, c, d;
int main()
{
	ios::sync_with_stdio(false);
	std::cout << std::setprecision(6) << std::fixed;
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	cout << "Sum : " << a + b + c + d << endl;
	cout << "Average : " << (a + b + c + d) / 4 << endl;
	cout << "Product : " << a * b * c * d << endl;
	cout << "MAX : " << max(max(a, b), max(c, d)) << endl;
	cout << "MIN : " << min(min(a, b), min(c, d)) << endl;
}
