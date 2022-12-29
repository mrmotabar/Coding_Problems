#include <iostream>
#include <Cstdio>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << min(a, b) << endl
		 << ((max(a, b)) - (min(a, b))) / 2;
}
