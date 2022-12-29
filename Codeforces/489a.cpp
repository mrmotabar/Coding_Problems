#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>> r;
int a[100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int j = i;
		for (int k = i; k < n; k++)
		{
			if (a[k] < a[j])
			{
				j = k;
			}
		}
		if (i != j)
		{
			swap(a[i], a[j]);
			r.push_back({i, j});
		}
	}
	// for(int i=0;i<n;i++){
	//	cout<<a[i]<<"  ";
	// }
	// cout<<r.size()<<endl;
	// for(int i=0;i<r.size();i++){
	//	cout<<r[i].first<<" "<<r[i].second<<endl;
	// }
}
