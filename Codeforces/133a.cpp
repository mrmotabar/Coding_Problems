#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	string p;
	cin >> p;
	int y = 1;
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == 'H' || p[i] == '9' || p[i] == 'Q')
		{
			cout << "YES";
			y = 0;
			break;
		}
	}
	if (y == 1)
	{
		cout << "NO";
	}
}
