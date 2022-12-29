#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int n, m;
	cin >> n >> m;
	long long int z = n / m;
	long long int u = n % m;
	long long int ans = (m - u) * (z) * (z - 1) / 2;
	ans += u * (z + 1) * (z) / 2;
	cout << ans << endl;
	cout << (n - m + 1) * (n - m) / 2;
}
