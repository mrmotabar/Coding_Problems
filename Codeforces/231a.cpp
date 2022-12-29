#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, t = 0, w1 = 0, w2 = 0, w3 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w1 >> w2 >> w3;
		if (w1 + w2 + w3 > 1)
		{
			t++;
		}
	}
	cout << t;
}
