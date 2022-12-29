#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int s1, s2, s3, s4, s5;
	cin >> a >> b >> c;
	s1 = a + b * c;
	s2 = a * (b + c);
	s3 = a * b * c;
	s4 = (a + b) * c;
	s5 = a + b + c;
	cout << max(max(max(s1, s2), max(s3, s4)), s5);
}
