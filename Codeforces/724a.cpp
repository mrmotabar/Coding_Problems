#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
string s[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
map<string, int> haf;
string a, b;
int main()
{
	haf["monday"] = 0;
	haf["tuesday"] = 1;
	haf["wednesday"] = 2;
	haf["thursday"] = 3;
	haf["friday"] = 4;
	haf["saturday"] = 5;
	haf["sunday"] = 6;
	cin >> a >> b;
	int x = 7, y = 3, z = 2;
	if ((s[(haf[a] + x) % 7] == b) || (s[(haf[a] + y) % 7] == b) || (s[(haf[a] + z) % 7] == b))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
