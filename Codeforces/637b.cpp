#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, int> mp;
string chat[2000 * 1000 + 10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> chat[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (!mp[chat[i]])
		{
			cout << chat[i] << endl;
			mp[chat[i]] = 1;
		}
	}
}
