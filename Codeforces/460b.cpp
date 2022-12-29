#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> ans;
long long int gr(int n)
{
	int s = 0;
	while (n > 0)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	for (int s = 1; s <= 81; s++)
	{
		int z = b * (pow(s, a)) + c;
		if (gr(z) == s && z <= 1000000000)
		{
			ans.push_back(z);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}
