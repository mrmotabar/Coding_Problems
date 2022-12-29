#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	int ans = 0;
	for (int i = 0; i <= 2 && i <= r && i <= b && i <= g; i++)
	{
		ans = max(ans, ((r - i) / 3 + (b - i) / 3 + (g - i) / 3 + i));
	}
	cout << ans;
}
