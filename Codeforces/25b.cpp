#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	string c;
	cin >> n >> c;
	int i = 0;
	while (n > 3)
	{
		cout << c[i] << c[i + 1] << "-";
		n -= 2;
		i += 2;
	}
	for (int j = i; j < c.size(); j++)
	{
		cout << c[j];
	}
}
