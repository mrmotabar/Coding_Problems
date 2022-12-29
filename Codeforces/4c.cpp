#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, int> name;
int main()
{
	int n = 0;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (name[s] == 0)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << s << name[s] << endl;
		}
		name[s]++;
	}
}
