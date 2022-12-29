#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int k2, k3, k5, k6, ans = 0;
	cin >> k2 >> k3 >> k5 >> k6;
	int a = min(k2, min(k5, k6));
	ans += a * 256;
	k2 -= a;
	k5 -= a;
	k6 -= a;
	ans += min(k3, k2) * 32;
	cout << ans;
}
