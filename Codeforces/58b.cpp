#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		if (n % i == 0)
		{
			cout << i << endl;
			n = i;
		}
	}
}
