#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int a, b, ans = 0;
	cin >> a >> b;
	while (b > 0)
	{
		ans += a / b;
		a %= b;
		swap(a, b);
	}
	cout << ans;
}
