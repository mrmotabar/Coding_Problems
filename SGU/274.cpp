
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int n, p;
	string s;
	bool cs[100], dot;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		cs[i] = true;
		getline(cin, s);
		dot = false;
		p = 0;
		if ((s[0] < 'a' && s[0] > 'z') || (s[0] < 'A' && s[0] > 'Z'))
		{
			cs[i] = false;
		}
		while (p < s.length() && s[p] != '@')
		{
			if (s[0] >= '0' && s[p] <= '9')
			{
				cs[i] = false;
			}
			// if(s[p]=='@'){
			//	cs[i]=true;
			// }
			if ((s[p] >= 'A' && s[p] <= 'Z') || (s[p] >= 'a' && s[p] <= 'z') || (s[p] == '_') || (s[p] == '-') || (s[p] >= '0' && s[p] <= '9') || (s[p] == '.'))
			{
			}
			else
			{
				cs[i] = false;
			}
			p++;
		}
		if (p == 0)
		{
			cs[i] = false;
		}
		else
		{
			p++;
			int u = 0;
			int sp = p;
			if (s[sp] == '.' || s[sp] == '@')
			{
				cs[i] = false;
			}
			while (p < s.length())
			{
				if (s[sp] >= '0' && s[sp] <= '9')
				{
					cs[i] = false;
				}
				int tdot = 0;
				if (s[p] == '.')
				{
					u = 1;
					for (int l = p + 1; l < s.size(); l++)
					{
						if (s[l] == '.')
						{
							tdot++;
						}
					}
				}
				if (tdot == 0 && u == 1)
				{
					dot = true;
					break;
				}
				if (s[p] == '_' || s[p] == '-' || s[p] == '.' || (s[p] >= '0' && s[p] <= '9'))
				{
				}
				else if ((s[p] < 'A') || (s[p] > 'Z' && s[p] < 'a') || (s[p] > 'z'))
				{
					cs[i] = false;
				}
				p++;
				// if(s[p]=='.'){
				//	dot=true;
				// }
			}
			if (p == (sp))
			{
				cs[i] = false;
			}
			else
			{
				p++;

				if (s.length() - p == 3 || s.length() - p == 2)
				{
					for (int j = p; j < s.size(); j++)
					{
						if ((s[p] < 'A') || (s[p] > 'Z' && s[p] < 'a') || (s[p] > 'z'))
						{
							cs[i] = false;
							break;
						}
					}
				}
				else
				{
					cs[i] = false;
				}
				if (cs[i] == true && dot == true)
				{
					cs[i] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (cs[i])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
