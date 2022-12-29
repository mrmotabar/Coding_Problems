#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int a = n % k;
	a = k - a;
	cout << n + a;
}
