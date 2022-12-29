#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << n * n / 4 << endl;
	for (int i = 1; i <= n; i += 2)
	{
		for (int j = 2; j <= n; j += 2)
		{
			cout << i << "  " << j << endl;
		}
	}
}
