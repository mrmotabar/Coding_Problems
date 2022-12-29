#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> x;
string s;
int main()
{
	s = 'A';
	string h;
	cin >> h;
	s += h;
	s += 'A';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
		{
			x.push_back(i);
		}
	}
	int max = 0;
	for (int i = 0; i < x.size() - 1; i++)
	{
		if (x[i + 1] - x[i] > max)
		{
			max = x[i + 1] - x[i];
		}
	}
	cout << max;
}
