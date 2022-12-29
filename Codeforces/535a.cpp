#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s[20], x[10];
	s[0] = "zero";
	s[1] = "one";
	s[2] = "two";
	s[3] = "three";
	s[4] = "four";
	s[5] = "five";
	s[6] = "six";
	s[7] = "seven";
	s[8] = "eight";
	s[9] = "nine";
	s[10] = "ten";
	s[11] = "eleven";
	s[12] = "	twelve";
	s[13] = "thirteen";
	s[14] = "fourteen";
	s[15] = "fifteen";
	s[16] = "sixteen";
	s[17] = "seventeen";
	s[18] = "eighteen";
	s[19] = "nineteen";
	x[2] = "twenty";
	x[3] = "thirty";
	x[4] = "forty";
	x[5] = "fifty";
	x[6] = "sixty";
	x[7] = "seventy";
	x[8] = "eighty";
	x[9] = "ninety";
	int n;
	cin >> n;
	if (n < 20)
	{
		cout << s[n];
	}
	else if (n % 10 == 0)
	{
		cout << x[n / 10];
	}
	else
	{
		cout << x[n / 10] << '-' << s[n % 10];
	}
}
