// problem 
// https://www.codingninjas.com/codestudio/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day_1169470?leftPanelTab=0 

#include <bits/stdc++.h>
using namespace std;

bool cmp1(pair<int, int> &p1, pair<int, int> &p2)
{
	if (p1.first != p2.first)
		return p1.first < p2.first;
	else
		return p1.second > p2.second;
}
int maxStock(vector<int> &prices, int n, int amount)
{
	// Write your code here
	int stocks = 0;
	vector<pair<int, int>> v(n + 1);
	for (int i = 0; i < n; i++)
		v[i + 1] = {prices[i], i + 1};
	sort(v.begin(), v.end(), cmp1);
	for (int i = 1; i <= n; i++)
	{
		if ((double(amount) / v[i].first) > v[i].second)
		{
			stocks = stocks + v[i].second;
			amount = amount - (v[i].first) * v[i].second;
		}
		else
		{
			stocks = stocks + (amount / v[i].first);
			amount = amount - (amount / v[i].first) * v[i].first;
		}
	}
	return stocks;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << maxStock(v, n, k) << endl;
	}
} 