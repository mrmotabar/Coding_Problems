#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[14] = {4, 44, 444, 7, 77, 777, 47, 74, 447, 474, 477, 744, 747, 774};
	int n;
	cin >> n;
	for (int i = 0; i < 14; i++)
	{
		if (n % a[i] == 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
