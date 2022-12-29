#include <iostream>
#include <cstdio>
using namespace std;
int d[100000];
int main()
{
	int n, a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	d[a] = 1;
	d[b] = 1;
	d[c] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (max(max(d[max(i - a, 0)], d[max(i - b, 0)]), (d[max(i - c, 0)])) > 0)
		{
			d[i] = max(max(d[max(i - a, 0)], d[max(i - b, 0)]), (d[max(i - c, 0)])) + 1;
		}
	}
	cout << d[n] << endl;
	//	for(int i=1;i<=n;i++){
	//		cout<<d[i]<<" ";
	//	}
}
