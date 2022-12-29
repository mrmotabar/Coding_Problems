#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(min(min(2 * (a + b), a + b + c), 2 * (b + c)), 2 * (a + c));
}
