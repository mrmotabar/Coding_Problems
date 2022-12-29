#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	double ans = 1000000.000;
	for (int i = 0; i < n; i++)
	{
		int x, y, v;
		cin >> x >> y >> v;
		ans = min(ans, (sqrt((a - x) * (a - x) + (b - y) * (b - y)) * 1.0) / v) * 1.0;
	}
	printf("%.6f", ans);
}
